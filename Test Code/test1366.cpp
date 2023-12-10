int AicpuOpUtil::MsTypeToProtoType(mindspore::TypeId ms_type) {
  auto iter = MS_PROTO_DATA_TYPE_MAP.find(ms_type);
  if (iter != MS_PROTO_DATA_TYPE_MAP.end()) {
    return iter->second;
  } else {
    // Return a default value if the input data type is not found
    return mindspore::DataType::MS_UNDEFINED;
  }
}
