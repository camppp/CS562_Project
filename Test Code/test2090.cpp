TraceContext SlRefractContext(const TraceContext *cxt, const ObjectInstance *obj)
{
  TraceContext refr_cxt = *cxt;

  refr_cxt.refract_depth++;
  refr_cxt.ray_context = CXT_REFRACT_RAY;

  // Calculate refracted ray direction using Snell's law
  double n1 = cxt->ray_context == CXT_REFRACT_RAY ? obj->GetRefractiveIndex() : 1.0;
  double n2 = cxt->ray_context == CXT_REFRACT_RAY ? 1.0 : obj->GetRefractiveIndex();
  Vector3 incident_dir = -cxt->ray.dir;  // Invert incident direction
  double cos_theta1 = DotProduct(incident_dir, cxt->hit_normal);
  double sin_theta2 = n1 / n2 * sqrt(std::max(0.0, 1.0 - cos_theta1 * cos_theta1));
  Vector3 refracted_dir = (n1 / n2) * incident_dir + ((n1 / n2 * cos_theta1 - sqrt(std::max(0.0, 1.0 - sin_theta2 * sin_theta2))) * cxt->hit_normal);

  // Update refracted ray's origin and direction in the new TraceContext
  refr_cxt.ray.origin = cxt->hit_point + EPSILON * refr_cxt.hit_normal;  // Move origin slightly along the normal
  refr_cxt.ray.dir = Normalize(refracted_dir);

  return refr_cxt;
}
