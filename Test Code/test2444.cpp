void CopyImage(const Image& src, const Image& dst, const Position& pos) {
  const auto src_width = src.config_.horizontal_resolution;
  const auto src_height = src.config_.vertical_resolution;

  const int copy_start_dst_x = std::max(pos.x, 0);
  const int copy_start_dst_y = std::max(pos.y, 0);
  const int copy_end_dst_x = std::min(pos.x + src_width, dst.config_.horizontal_resolution);
  const int copy_end_dst_y = std::min(pos.y + src_height, dst.config_.vertical_resolution);

  const auto bytes_per_pixel = (src.config_.bits_per_pixel + 7) / 8;
  const auto bytes_per_copy_line = bytes_per_pixel * (copy_end_dst_x - copy_start_dst_x);

  for (int y = copy_start_dst_y; y < copy_end_dst_y; ++y) {
    const auto src_y = pos.y + (y - copy_start_dst_y);
    const auto dst_y = y;

    for (int x = copy_start_dst_x; x < copy_end_dst_x; ++x) {
      const auto src_x = pos.x + (x - copy_start_dst_x);
      const auto dst_x = x;

      for (size_t byte = 0; byte < bytes_per_pixel; ++byte) {
        dst.buffer_[dst_y * dst.config_.stride + dst_x * bytes_per_pixel + byte] =
            src.buffer_[src_y * src.config_.stride + src_x * bytes_per_pixel + byte];
      }
    }
  }
}
