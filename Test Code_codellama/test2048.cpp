public String getShaderFromLibrary(String shaderName) {
    // Check if the shader exists in the library
    if (shaderName in shaderLibrary) {
        return shaderLibrary[shaderName];
    } else {
        // Return a default shader if the specified shader does not exist in the library
        return "defaultShader";
    }
}
