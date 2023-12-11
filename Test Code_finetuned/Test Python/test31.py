class KvpHeapObjectFactory(HeapObjectFactory):
    def __init__(self, obj, options=None):
        super().__init__(options)
        self._items = obj
        self._object_id = self.get_object_id()
        self._max_len = options.max_size if options and options.max_size else len(obj)
        self._render_options = options.render_options if options and options.render_options else None