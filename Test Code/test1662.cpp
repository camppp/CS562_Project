class filter_proxy:
    def __init__(self):
        self.elements = []

    def add_element(self, element):
        self.elements.append(element)

    def apply_filter(self, predicate):
        self.filtered_elements = list(filter(predicate, self.elements))

    def get_filtered_elements(self):
        return self.filtered_elements
