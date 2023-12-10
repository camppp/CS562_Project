void addDemandBranch(model::Model& model, model::PlantLoop& plantLoop, model::CurveBiquadratic& demandCurve) {
    // Create a new demand component using the provided biquadratic curve object
    model::DemandComponent newDemandComponent(model);
    newDemandComponent.setPerformanceCurve(demandCurve);

    // Add the new demand component to the plant loop system
    plantLoop.addDemandComponent(newDemandComponent);

    // Verify that the demand component has been successfully added to the plant loop system
    std::vector<model::DemandComponent> demandComponents = plantLoop.demandComponents();
    bool componentAdded = false;
    for (const auto& component : demandComponents) {
        if (component == newDemandComponent) {
            componentAdded = true;
            break;
        }
    }
    assert(componentAdded);
}
