python
from typing import List, Tuple

def process_image(image: List[List[Tuple[int, int, int]]], img_bytes_per_line: int) -> List[List[int]]:
    grayscale_image = []
    for row in image:
        grayscale_row = []
        for pixel in row:
            grayscale_intensity = sum(pixel) // 3  # Calculate average of r, g, b values
            grayscale_row.append(grayscale_intensity)
        grayscale_image.append(grayscale_row)
    return grayscale_image
