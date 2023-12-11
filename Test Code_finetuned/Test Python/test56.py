import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Activation

class NeuralNetwork:
    def __init__(self):
        self.model = Sequential()

    def add_layer(self, units):
        """
        Add a dense layer to the model with the specified number of units.

        Args:
        units: int, number of units in the dense layer.

        Returns:
        None
        """
        self.model.add(Dense(units))

    def set_activation(self, activation):
        """
        Set the activation function for the last added layer.

        Args:
        activation: string, name of the activation function.

        Returns:
        None
        """
        self.model.add(Activation(activation))

    def compile_model(self, optimizer, loss):
        """
        Compile the model with the specified optimizer and loss function.

        Args:
        optimizer: string, name of the optimizer.
        loss: string, name of the loss function.

        Returns:
        None
        """
        self.model.compile(optimizer=optimizer, loss=loss)