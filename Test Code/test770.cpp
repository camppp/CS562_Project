template <typename LabelType>
LabelType map_label_type_to_label(VW::label_type_t type) {
  switch (type) {
    case VW::label_type_t::cs:
      return COST_SENSITIVE::cs_label{};
    case VW::label_type_t::multilabel:
      return MULTILABEL::multilabel{};
    case VW::label_type_t::multiclass:
      return MULTICLASS::mc_label{};
    case VW::label_type_t::ccb:
      return CCB::ccb_label{};
    default:
      throw std::invalid_argument("Invalid label type");
  }
}
