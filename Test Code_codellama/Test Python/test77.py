class SkyboxManager:
    def __init__(self, blackside_pack_name):
        self.blackside_pack_name = blackside_pack_name

    def load_skybox_black_side(self):
        return loader.loadModel(self.blackside_pack_name + "cubemap.bam")