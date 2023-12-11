import ctypes

class BufferManager:
    def __init__(self, buffer_size):
        self.buffer = (ctypes.c_float * buffer_size)()
        self.mapped_range = None
        self.mapped_access_mode = None

    def map_buffer(self, range_start, range_end, access_mode):
        if self.mapped_range is not None:
            raise ValueError("Buffer is already mapped")
        if range_start < 0 or range_start >= buffer_size or range_end < 0 or range_end >= buffer_size:
            raise ValueError("Invalid range")
        if access_mode not in (GL_READ_ONLY, GL_WRITE_ONLY, GL_READ_WRITE):
            raise ValueError("Invalid access mode")
        self.mapped_range = range(range_start, range_end)
        self.mapped_access_mode = access_mode
        return self.buffer[range_start:range_end]

    def flush_range(self, range_start, range_end):
        if self.mapped_range is None:
            raise ValueError("Buffer is not mapped")
        if range_start < 0 or range_start >= buffer_size or range_end < 0 or range_end >= buffer_size:
            raise ValueError("Invalid range")
        if range_start > range_end:
            raise ValueError("Invalid range")
        if range_start < self.mapped_range[0] or range_end > self.mapped_range[1]:
            raise ValueError("Range is not mapped")
        if self.mapped_access_mode == GL_READ_ONLY:
            raise ValueError("Cannot flush read-only range")
        self.mapped_range[0] = range_start
        self.mapped_range[1] = range_end

    def unmap_buffer(self):
        if self.mapped_range is None:
            raise ValueError("Buffer is not mapped")
        self.mapped_range = None
        self.mapped_access_mode = None