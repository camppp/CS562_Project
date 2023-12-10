int AicpuOpUtil::MsTypeToProtoType(mindspore::TypeId ms_type) {
  auto it = MS_PROTO_DATA_TYPE_MAP.find(ms_type);
  if (it != MS_PROTO_DATA_TYPE_MAP.end()) {
    return it->second;
  }
  return mindspore::DataType::MS_FLOAT32;
}
