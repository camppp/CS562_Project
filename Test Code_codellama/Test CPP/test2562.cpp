Vector calculateNextVector(Part part, int segment_idx, ConnectionSegment segment)
{
    // Calculate the next segment index
    int next_segment_idx = (segment_idx + 1) % part.connection.segments.size();

    // Calculate the next vector
    Vector next_vector;
    if (next_segment_idx == 0)
    {
        // If the next segment is the first one for the part, use the first segment's start point
        next_vector = part.connection.segments[0].to - segment.to;
    }
    else
    {
        // Otherwise, use the next segment's start point
        next_vector = part.connection.segments[next_segment_idx].to - segment.to;
    }

    return next_vector;
}
