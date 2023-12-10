#include <openvr.h>

vr::EVRInitError SetVRDeviceProperties(vr::PropertyContainerHandle_t propertyContainer) {
    vr::VRProperties()->SetInt32Property(propertyContainer, vr::Prop_ControllerHandSelectionPriority_Int32, -1);
    vr::VRProperties()->SetStringProperty(propertyContainer, vr::Prop_NamedIconPathDeviceOff_String, "{htc}/icons/tracker_status_off.png");
    vr::VRProperties()->SetStringProperty(propertyContainer, vr::Prop_NamedIconPathDeviceSearching_String, "{htc}/icons/tracker_status_searching.gif");
    vr::VRProperties()->SetStringProperty(propertyContainer, vr::Prop_NamedIconPathDeviceSearchingAlert_String, "{htc}/icons/tracker_status_searching_alert.gif");
    vr::VRProperties()->SetStringProperty(propertyContainer, vr::Prop_NamedIconPathDeviceReady_String, "{htc}/icons/tracker_status_ready.png");
    vr::VRProperties()->SetStringProperty(propertyContainer, vr::Prop_NamedIconPathDeviceReadyAlert_String, "{htc}/icons/tracker_status_ready_alert.png");
    vr::VRProperties()->SetStringProperty(propertyContainer, vr::Prop_NamedIconPathDeviceNotReady_String, "{htc}/icons/tracker_status_error.png");
    vr::VRProperties()->SetStringProperty(propertyContainer, vr::Prop_NamedIconPathDeviceStandby_String, "{htc}/icons/tracker_status_standby.png");
    vr::VRProperties()->SetStringProperty(propertyContainer, vr::Prop_NamedIconPathDeviceAlertLow_String, "{htc}/icons/tracker_status_ready_low.png");
    vr::VRProperties()->SetBoolProperty(propertyContainer, vr::Prop_HasDisplayComponent_Bool, false);
    vr::VRProperties()->SetBoolProperty(propertyContainer, vr::Prop_HasCameraComponent_Bool, false);
    vr::VRProperties()->SetBoolProperty(propertyContainer, vr::Prop_HasDriverDirectModeComponent_Bool, false);
    vr::VRProperties()->SetBoolProperty(propertyContainer, vr::Prop_HasVirtualDisplayComponent_Bool, false);
    return vr::VRInitError_None;
}
