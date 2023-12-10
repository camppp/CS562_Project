java
public String getShaderFromLibrary(String shaderName) {
    Map<String, String> shaderLibrary = new HashMap<>();
    // Populate the shader library with shader names and their corresponding shaders
    shaderLibrary.put("shader1", "shader_code_1");
    shaderLibrary.put("shader2", "shader_code_2");
    shaderLibrary.put("shader3", "shader_code_3");

    // Retrieve the shader from the library based on the given shader name
    String selectedShader = shaderLibrary.getOrDefault(shaderName, "default_shader_code");

    return selectedShader;
}
