void SetVRDeviceProperties(vr::IVRPropertyContainer* propertyContainer) {
  // Set integer properties
  propertyContainer->SetIntegerProperty(vr::k_Prop_Device_Integer, 123);
  propertyContainer->SetIntegerProperty(vr::k_Prop_Device_Integer2, 456);

  // Set string properties
  propertyContainer->SetStringProperty(vr::k_Prop_Device_String, "Hello World");
  propertyContainer->SetStringProperty(vr::k_Prop_Device_String2, "Goodbye World");

  // Set boolean properties
  propertyContainer->SetBooleanProperty(vr::k_Prop_Device_Boolean, true);
  propertyContainer->SetBooleanProperty(vr::k_Prop_Device_Boolean2, false);

  // Set device state properties
  propertyContainer->SetStringProperty(vr::k_Prop_Device_State, "off");
  propertyContainer->SetStringProperty(vr::k_Prop_Device_State2, "searching");
  propertyContainer->SetStringProperty(vr::k_Prop_Device_State3, "ready");

  // Set device component properties
  propertyContainer->SetBooleanProperty(vr::k_Prop_Device_Component_Present, true);
  propertyContainer->SetBooleanProperty(vr::k_Prop_Device_Component_Present2, false);
}
