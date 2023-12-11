std::string processFilePath(const std::string& file_name) {
  if (kUseApiDef) {
    return "tensorflow/core/api_def/python_api/" + file_name;
  } else {
    return "tensorflow/core/api_def/base_api/" + file_name;
  }
}
