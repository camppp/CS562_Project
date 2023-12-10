Variant ConvertTo64BitInteger(const Variant& variant) {
    switch (variant.GetType()) {
        case VariantType::Double:
            return static_cast<int64_t>(variant.GetValue<double>());
        case VariantType::Float:
            return static_cast<int64_t>(variant.GetValue<float>());
        case VariantType::Int32:
            return static_cast<int64_t>(variant.GetValue<int32_t>());
        case VariantType::Int64:
            return variant.GetValue<int64_t>();
        default:
            throw std::invalid_argument("Unsupported data type");
    }
}
