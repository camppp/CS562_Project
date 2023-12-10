python
class GraphicsConfigManager:
    def __init__(self, max_uav_barriers, max_shader_arguments, max_shader_samplers):
        self.max_uav_barriers = max_uav_barriers
        self.max_shader_arguments = max_shader_arguments
        self.max_shader_samplers = max_shader_samplers

    def getMaxUAVBarriers(self):
        return self.max_uav_barriers

    def getMaxShaderArguments(self):
        return self.max_shader_arguments

    def getMaxShaderSamplers(self):
        return self.max_shader_samplers

    def updateMaxUAVBarriers(self, newMaxUAVBarriers):
        if newMaxUAVBarriers <= 0:
            print("Error: Max UAV barriers must be a positive integer.")
        else:
            self.max_uav_barriers = newMaxUAVBarriers

    def updateMaxShaderArguments(self, newMaxShaderArguments):
        if newMaxShaderArguments <= 0:
            print("Error: Max shader arguments must be a positive integer.")
        else:
            self.max_shader_arguments = newMaxShaderArguments

    def updateMaxShaderSamplers(self, newMaxShaderSamplers):
        if newMaxShaderSamplers <= 0:
            print("Error: Max shader samplers must be a positive integer.")
        else:
            self.max_shader_samplers = newMaxShaderSamplers

# Example usage
configManager = GraphicsConfigManager(8, 4, 16)
print(configManager.getMaxUAVBarriers())  # Output: 8
print(configManager.getMaxShaderArguments())  # Output: 4
print(configManager.getMaxShaderSamplers())  # Output: 16

configManager.updateMaxUAVBarriers(10)
print(configManager.getMaxUAVBarriers())  # Output: 10

configManager.updateMaxShaderArguments(6)
print(configManager.getMaxShaderArguments())  # Output: 6

configManager.updateMaxShaderSamplers(20)  # Output: 20
print(configManager.getMaxShaderSamplers())  # Output: 20
