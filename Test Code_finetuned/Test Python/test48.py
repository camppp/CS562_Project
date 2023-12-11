import numpy as np

class NeuralNetwork:
    def __init__(self):
        self.params = {}
        self.fitted_ = False

    def _init_params(self, X):
        n_features = X.shape[1]
        self.params['W'] = np.random.randn(n_features, 1)
        self.params['b'] = np.random.randn(1)
        self.fitted_ = True