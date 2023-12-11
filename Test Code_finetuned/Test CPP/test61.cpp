void install_instance(const ::Deployment::DeploymentPlan &plan, ::CORBA::ULong instanceRef, ::CORBA::Any_out instance_reference) {
    // Allocate memory for the instance reference
    ::CORBA::Any *any_ptr = nullptr;
    ACE_NEW_THROW_EX (any_ptr, ::CORBA::Any (), CORBA::NO_MEMORY ());

    // Set the instance reference in the output parameter
    any_ptr->type ((CORBA::TypeCode_ptr) CORBA::_tc_ulong.in ());
    any_ptr->from_ulong (instanceRef);

    // Assign the output parameter
    instance_reference = any_ptr;
}