Vector calculateNextVector(Part part, int segment_idx, ConnectionSegment segment) {
    Vector next_vector;
    if (segment_idx < part.connection.segments.size() - 1) {
        WeaveConnectionSegment& next_segment = part.connection.segments[segment_idx + 1];
        next_vector = next_segment.to - segment.to;
    } else {
        next_vector = part.connection.segments[0].to - segment.to;
    }
    return next_vector;
}
