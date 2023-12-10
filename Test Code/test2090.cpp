TraceContext* SlRefractContext(const TraceContext* cxt, const ObjectInstance* obj) {
  // Create a new trace context for the refracted ray
  TraceContext* new_cxt = new TraceContext();

  // Copy the original context properties
  new_cxt->origin = cxt->origin;
  new_cxt->direction = cxt->direction;
  new_cxt->tmin = cxt->tmin;
  new_cxt->tmax = cxt->tmax;
  new_cxt->depth = cxt->depth;

  // Calculate the refracted ray direction
  float n1 = obj->material->refractiveIndex;
  float n2 = cxt->material->refractiveIndex;
  float cos_i = dot(cxt->direction, obj->normal);
  float sin_t2 = n1 * sin(cxt->direction.length()) / n2;
  float cos_t = sqrt(1.0 - sin_t2);
  float t = acos(cos_t);
  float sin_i = sin(t);
  float cos_i = cos(t);
  float sin_t = sin(t);
  float cos_t = cos(t);
  float3 refracted_direction = normalize(cxt->direction * n1 / n2 - obj->normal * (n1 * cos_i - n2 * cos_t));

  // Update the refracted ray's origin and direction
  new_cxt->origin = cxt->origin + cxt->direction * cxt->tmin;
  new_cxt->direction = refracted_direction;

  return new_cxt;
}
