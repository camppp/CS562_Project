import numpy as np

class InputDataGenerator:
    def __init__(self, batch_size):
        self.input_data = {}
        self.batch_size = batch_size

    def generate_input_data(self, input_nodes):
        for node in input_nodes:
            shape = [self.batch_size if dim.dim[0] <= 0 else dim.dim[0] for dim in node.type.tensor_type.shape.dim]
            if node.type.tensor_type.elem_type == 1:
                data = np.random.randn(*shape).astype(np.float32)
            elif node.type.tensor_type.elem_type == 7:
                data = np.random.randint(0, 100, shape).astype(np.int64)
            elif node.type.tensor_type.elem_type == 9:
                data = np.random.choice([True, False], size=shape)
            else:
                raise ValueError("Unsupported data type")
            self.input_data[node.name] = data