import ctypes

class BufferManager:
    def __init__(self, buffer_id, buffer_size):
        self.buffer_id = buffer_id
        self.buffer_size = buffer_size
        self.mapped_range = None

    def map_buffer(self, range_start, range_end, access_mode):
        if self.mapped_range is not None:
            raise Exception("A range is already mapped")
        if range_start < 0 or range_end > self.buffer_size or range_start > range_end:
            raise Exception("Invalid range")
        self.mapped_range = (range_start, range_end, access_mode)
        return ctypes.c_void_p(range_start)

    def flush_range(self, range_start, range_end):
        if self.mapped_range is None:
            raise Exception("No range is mapped")
        if range_start < self.mapped_range[0] or range_end > self.mapped_range[1]:
            raise Exception("Invalid range")
        # Flush the range here

    def unmap_buffer(self):
        if self.mapped_range is None:
            raise Exception("No range is mapped")
        # Unmap the buffer here
        self.mapped_range = None