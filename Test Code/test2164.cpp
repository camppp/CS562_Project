#include <vector>
#include <cmath>

// Define the sigmoid function
float sigmoid(int x) {
    return 1 / (1 + exp(-x));
}

// Define the fitness evaluation function
float evaluateFitness(const std::vector<float>& outputValues) {
    float fitness = 0;

    // Step 2: Subtract 1-c from fitness for each output value c
    for (float c : outputValues) {
        fitness -= 1 - c;
    }

    // Step 3: Evaluate the neural network for input {1, 1} and subtract the output value from fitness
    float d = nn->evaluate({1, 1})->output[0]->value;
    fitness -= d;

    // Step 4: Check the condition and update fitness and j
    if (nn->output[0]->nImpulses > 0 && nn->output[0]->nImpulses != nn->output[0]->inputs) {
        nn->showInfo();
        int j = 0;  // Initialize j to 0
        j++;  // Increment j by 1
    }

    // Step 5: Add -sigmoid(nn->hidden.size())+1 to fitness
    fitness += -sigmoid(nn->hidden.size()) + 1;

    return fitness;
}
