from screws.freeze.main import FrozenOnly
from root.config.main import sIze

class _2dCSCG_Mesh_DO_FIND(FrozenOnly):
    def __init__(self, meshDO, mesh):
        self._DO_ = meshDO
        self._mesh_ = mesh

    def find_elements(self, element_type):
        if element_type == "triangle":
            return [i for i, element in enumerate(self._mesh_.elements) if isinstance(element, Triangle)]
        elif element_type == "quadrilateral":
            return [i for i, element in enumerate(self._mesh_.elements) if isinstance(element, Quadrilateral)]
        elif element_type == "node":
            return [i for i, element in enumerate(self._mesh_.elements) if isinstance(element, Node)]
        else:
            raise ValueError("Invalid element_type. Supported types are 'triangle', 'quadrilateral', and 'node'.")