import tensorflow as tf

class ImageProcessor:
    def __init__(self, ph_mean, ph_std):
        self.ph_mean = ph_mean
        self.ph_std = ph_std

    def process_image(self, ph):
        # Reshape the input tensor and extract a subset of data
        subset = tf.slice(ph, [0, 0, 0, 0], [-1, -1, -1, -1])

        # Normalize the extracted data
        normalized = tf.divide(tf.subtract(subset, self.ph_mean), self.ph_std)

        # Apply a series of convolutional operations
        conv1 = tf.layers.conv2d(normalized, filters=32, kernel_size=[5, 5], padding="same", activation=tf.nn.relu)
        pool1 = tf.layers.max_pooling2d(conv1, pool_size=[2, 2], strides=2)
        conv2 = tf.layers.conv2d(pool1, filters=64, kernel_size=[5, 5], padding="same", activation=tf.nn.relu)
        pool2 = tf.layers.max_pooling2d(conv2, pool_size=[2, 2], strides=2)

        return pool2