template <typename T, typename SegmentType, typename Func>
void resolve_segment_type(const AbstractSegment& segment, Func&& func) {
  if (auto* typed_segment = dynamic_cast<const SegmentType*>(&segment)) {
    func(*typed_segment);
  } else {
    Fail("Failed to resolve segment type");
  }
}

template <typename T, typename ReferencedSegment>
class SingleChunkReferenceSegmentAccessor {
 public:
  SingleChunkReferenceSegmentAccessor(const std::vector<ChunkOffset>& pos_list, ChunkID chunk_id,
                                      const ReferencedSegment& referenced_segment) {
    // Initialize the accessor with the provided parameters
    // ...
  }
  // Other member functions and data members can be added as per requirements
};
