size_t numLights = this->ShadowTextureUnits.size();

for (size_t i = 0; i < numLights; ++i)
{
  std::ostringstream toString1;
  std::ostringstream toString2;
  toString1 << "diffuse += (df * lightColor" << i << ");";
  toString2 << "diffuse += (df * factor" << i << " * lightColor" << i << ");";
  vtkShaderProgram::Substitute(fragmentShader,
    toString1.str(), toString2.str(),
    false);
  std::ostringstream toString3;
  std::ostringstream toString4;
  toString3 << "specular += (df * lightColor" << i << ");";
  toString4 << "specular += (df * factor" << i << " * lightColor" << i << ");";
  vtkShaderProgram::Substitute(fragmentShader,
    toString3.str(), toString4.str(),
    false);
}
