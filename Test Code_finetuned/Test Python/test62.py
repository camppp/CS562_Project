import random
from typing import List

class AudioIODataset:
    def __init__(self):
        self.data = []

    def add_data(self, data, label):
        self.data.append((data, label))

def shuffle_files_and_create_dataset(file_paths: List[str], labels: List[str], shuffle: bool) -> AudioIODataset:
    if shuffle:
        combined = list(zip(file_paths, labels))
        random.shuffle(combined)
        file_paths[:], labels[:] = zip(*combined)

    dataset = AudioIODataset()
    for file_path, label in zip(file_paths, labels):
        # Assuming load_audio_data is a function that loads audio data from a file
        data = load_audio_data(file_path)
        dataset.add_data(data, label)

    return dataset