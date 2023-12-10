void movimentador::buscaLocal(const dataset& dataset, const int& maxIterFO) {
  // Initialize the best solution found so far
  int bestFitness = 0;
  int bestTempo = 0;
  int bestAlocsMap = 0;
  int bestGastos = 0;
  int bestTotalFree = 0;

  // Perform the local search
  for (int i = 0; i < maxIterFO; i++) {
    // Generate a new solution
    int newTempo = 0;
    int newAlocsMap = 0;
    int newFitness = 0;
    int newGastos = 0;
    int newTotalFree = 0;

    // Calculate the fitness of the new solution
    newFitness = calculateFitness(newTempo, newAlocsMap, newGastos, newTotalFree);

    // Compare the fitness of the new solution with the best solution found so far
    if (newFitness > bestFitness) {
      // Update the best solution found so far
      bestFitness = newFitness;
      bestTempo = newTempo;
      bestAlocsMap = newAlocsMap;
      bestGastos = newGastos;
      bestTotalFree = newTotalFree;
    }
  }

  // Return the best solution found so far
  return bestTempo, bestAlocsMap, bestFitness, bestGastos, bestTotalFree;
}

int movimentador::calculateFitness(int tempo, int alocsMap, int gastos, int totalFree) {
  // Calculate the fitness of the solution
  int fitness = 0;

  // Calculate the fitness based on the criteria
  fitness += tempo * dataset.getDelta();
  fitness += alocsMap * dataset.getDelta();
  fitness += gastos * dataset.getDelta();
  fitness += totalFree * dataset.getDelta();

  return fitness;
}
