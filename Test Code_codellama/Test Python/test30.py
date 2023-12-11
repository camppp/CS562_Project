class KvpHeapObjectFactory(HeapObjectFactory):
    def __init__(self, obj, options=None):
        self._items = None
        self._object_id = None
        self._max_len = None
        self._render_options = None

        # TODO: Implement this method

    @property
    def items(self):
        return self._items

    @property
    def object_id(self):
        return self._object_id

    @property
    def max_len(self):
        return self._max_len

    @property
    def render_options(self):
        return self._render_options

    def get_object_repr(self):
        return "{{{}}}".format(", ".join("{}={}".format(k, v) for k, v in self._items))

    def get_object_str(self):
        return str(self._items)

    def get_object_bytes(self):
        return bytes(self._items)