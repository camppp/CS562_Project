python
def countNonEmptyLines(labels_file_path, images_file_path):
    classes_qtd = 0
    images_qtd = 0
    
    with open(labels_file_path, 'r') as labels_file:
        for line in labels_file:
            if line.strip():
                classes_qtd += 1
    
    with open(images_file_path, 'r') as images_file:
        for line in images_file:
            if line.strip():
                images_qtd += 1
    
    return classes_qtd + images_qtd

# Example usage
labels_file_path = "config/labels.txt"
images_file_path = "config/train.txt"
total_non_empty_lines = countNonEmptyLines(labels_file_path, images_file_path)
print("Total count of non-empty lines in both files:", total_non_empty_lines)
