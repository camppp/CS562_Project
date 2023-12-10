template <typename T>
void resolve_segment_type(const ReferenceSegment& referenced_segment,
                          const std::function<void(const auto&)>& lambda) {
  using ReferencedSegment = std::decay_t<decltype(referenced_segment)>;
  if constexpr (!std::is_same_v<ReferencedSegment, ReferenceSegment>) {
    lambda(referenced_segment);
  } else {
    Fail("Encountered nested ReferenceSegments");
  }
}

template <typename T>
class SingleChunkReferenceSegmentAccessor {
 public:
  SingleChunkReferenceSegmentAccessor(const std::vector<ChunkID>& pos_list,
                                      ChunkID chunk_id,
                                      const ReferencedSegment& referenced_segment)
      : pos_list_(pos_list),
        chunk_id_(chunk_id),
        referenced_segment_(referenced_segment) {}

  T operator[](ChunkID chunk_id) const {
    return referenced_segment_[pos_list_[chunk_id]];
  }

 private:
  std::vector<ChunkID> pos_list_;
  ChunkID chunk_id_;
  ReferencedSegment referenced_segment_;
};
