void install_instance(const ::Deployment::DeploymentPlan &plan,
                      ::CORBA::ULong instanceRef,
                      ::CORBA::Any_out instance_reference)
{
    // Create a new instance of the component type
    ::CORBA::Any instance = plan.componentType.createInstance();

    // Set the instance reference in the output parameter
    instance_reference = instance;

    // Install the instance using the deployment plan
    plan.installInstance(instanceRef, instance);
}
