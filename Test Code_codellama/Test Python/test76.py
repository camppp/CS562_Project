class StandfordBackgroundDataset(CustomDataset):
    def __init__(self, img_suffix='.png', seg_map_suffix='.png', split='train', **kwargs):
        super().__init__(img_suffix, seg_map_suffix, split, **kwargs)

        # Initialize the dataset with the given parameters
        self.img_suffix = img_suffix
        self.seg_map_suffix = seg_map_suffix
        self.split = split

        # Load the dataset
        self.img_dir = os.path.join(self.root, 'images')
        self.seg_map_dir = os.path.join(self.root, 'segmentation_maps')
        self.img_list = []
        self.seg_map_list = []
        for img_file in os.listdir(self.img_dir):
            if img_file.endswith(img_su)