void GeneticAlgorithm::evolve() {
    // Select two parent genomes based on their fitness
    const int parent1Index = selectParent();
    const int parent2Index = selectParent();
    const Genome& parent1 = population[parent1Index];
    const Genome& parent2 = population[parent2Index];

    // Apply crossover and mutation to create new genomes
    std::array<Genome, PopSize> newPopulation;
    for (int i = 0; i < PopSize; i++) {
        if (i == parent1Index || i == parent2Index) {
            // Use the selected parents as is
            newPopulation[i] = population[i];
        } else {
            // Apply crossover and mutation to create a new genome
            newPopulation[i] = parent1.crossover(parent2);
            newPopulation[i].mutate();
        }
    }

    // Replace the old population with the new generation of genomes
    replacePopulation(newPopulation);
}
