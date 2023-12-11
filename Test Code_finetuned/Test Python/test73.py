import numpy as np

class CustomLayer:
    def __init__(self, input_size, output_size, std_dev=0.01, reg_coeff=0.01, momentum=0.9):
        self.input_size = input_size
        self.output_size = output_size
        self.std_dev = std_dev
        self.reg_coeff = reg_coeff
        self.momentum = momentum

        self.weights = np.random.normal(loc=0.0, scale=self.std_dev, size=(input_size, output_size))
        self.biases = np.zeros(output_size)
        self.velocity_weights = np.zeros((input_size, output_size))
        self.velocity_biases = np.zeros(output_size)

    def apply_regularization(self):
        self.weights -= self.reg_coeff * self.weights
        self.biases -= self.reg_coeff * self.biases

    def forward(self, input_data):
        self.input_data = input_data
        self.output = np.dot(self.input_data, self.weights) + self.biases
        return self.output

    def backward(self, grad_output):
        grad_weights = np.dot(self.input_data.T, grad_output)
        grad_biases = np.sum(grad_output, axis=0)

        self.velocity_weights = self.momentum * self.velocity_weights - self.reg_coeff * self.weights
        self.velocity_biases = self.momentum * self.velocity_biases - self.reg_coeff * self.biases

        self.weights += self.velocity_weights
        self.biases += self.velocity_biases

        return np.dot(grad_output, self.weights.T)