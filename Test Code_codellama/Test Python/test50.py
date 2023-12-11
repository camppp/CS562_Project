from screws.freeze.main import FrozenOnly
from root.config.main import sIze

class _2dCSCG_Mesh_DO_FIND(FrozenOnly):
    def __init__(self, meshDO):
        self._DO_ = meshDO
        self._mesh_ = meshDO.mesh

    def find_elements(self, element_type):
        if element_type == "triangle":
            return self._mesh_.triangles
        elif element_type == "quadrilateral":
            return self._mesh_.quadrilaterals
        elif element_type == "node":
            return self._mesh_.nodes
        else:
            raise ValueError(f"Invalid element type: {element_type}")