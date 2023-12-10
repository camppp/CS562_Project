Variable nansum(const Variable &var, const Dim dim, const Masks &masks) {
  if (const auto mask_union = irreducible_mask(masks, dim);
      mask_union.is_valid()) {
    // Exclude elements based on the irreducible mask and recursively call nansum
    return nansum(where(mask_union, zero_like(var), var), dim, masks);
  } else {
    // Calculate the sum of non-NaN elements along the specified dimension
    switch (dim) {
      case Dim::ROW:
        return sum(where(isnan(var), 0, var), Dim::ROW);
      case Dim::COLUMN:
        return sum(where(isnan(var), 0, var), Dim::COLUMN);
      // Handle additional dimensions as needed
      default:
        throw std::invalid_argument("Invalid dimension specified");
    }
  }
}
