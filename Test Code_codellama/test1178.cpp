void addDemandBranch(model::Model& model, model::PlantLoop& plantLoop, model::CurveBiquadratic& demandCurve) {
  // Create a new demand component using the provided biquadratic curve object
  auto newDemandComponent = model::DemandComponent(demandCurve);

  // Add the new demand component to the plant loop system
  plantLoop.addDemandComponent(newDemandComponent);

  // Verify that the demand component has been successfully added to the plant loop system
  if (plantLoop.getDemandComponents().contains(newDemandComponent)) {
    // Demand component has been successfully added
  } else {
    // Demand component has not been added
  }
}
