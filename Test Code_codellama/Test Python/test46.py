class NeuralNetwork:
    def __init__(self, layers):
        self.layers = layers
        self.params = {}
        self.fitted_ = False

    def _init_params(self, X):
        # Initialize the weights and biases for each layer
        for i in range(len(self.layers)):
            self.params['W' + str(i)] = np.random.rand(self.layers[i], self.layers[i-1])
            self.params['b' + str(i)] = np.zeros((self.layers[i], 1))

        # Initialize the activation functions for each layer
        for i in range(len(self.layers)):
            self.params['activation' + str(i)] = 'relu'

        # Initialize the learning rate
        self.params['learning_rate'] = 0.01

        # Initialize the regularization parameter
        self.params['regularization'] = 0.01
