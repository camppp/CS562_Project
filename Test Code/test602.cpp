void GeneticAlgorithm::evolve() {
    std::array<Genome, PopSize> newPopulation;

    // Create the new generation of genomes
    for (int i = 0; i < PopSize; i += 2) {
        // Select parent genomes based on their fitness
        const Genome& parent1 = selectParentByFitness(population);
        const Genome& parent2 = selectParentByFitness(population);

        // Apply crossover and mutation to create new genomes
        Genome child1 = parent1;
        Genome child2 = parent2;
        child1.crossover(parent2);
        child2.crossover(parent1);
        child1.mutate();
        child2.mutate();

        newPopulation[i] = child1;
        newPopulation[i + 1] = child2;
    }

    // Replace the old population with the new generation of genomes
    replacePopulation(newPopulation);
}
