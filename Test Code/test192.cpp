python
def non_maximum_suppression(bounding_boxes, confidence_scores, overlap_threshold):
    # Combine bounding boxes with confidence scores
    boxes_with_scores = [(box, score) for box, score in zip(bounding_boxes, confidence_scores)]
    
    # Sort the bounding boxes based on confidence scores in descending order
    sorted_boxes = sorted(boxes_with_scores, key=lambda x: x[1], reverse=True)
    
    selected_boxes = []
    
    for box, score in sorted_boxes:
        # Calculate the area of overlap with previously selected boxes
        overlaps = [calculate_overlap(box, sel_box) for sel_box in selected_boxes]
        
        # If no overlap or overlap area below threshold, add the box to selected list
        if not any(overlap > overlap_threshold for overlap in overlaps):
            selected_boxes.append(box)
    
    return selected_boxes

def calculate_overlap(box1, box2):
    # Calculate the intersection area of two bounding boxes
    intersection = max(0, min(box1[2], box2[2]) - max(box1[0], box2[0])) * max(0, min(box1[3], box2[3]) - max(box1[1], box2[1]))
    
    # Calculate the union area of two bounding boxes
    area1 = (box1[2] - box1[0]) * (box1[3] - box1[1])
    area2 = (box2[2] - box2[0]) * (box2[3] - box2[1])
    union = area1 + area2 - intersection
    
    # Calculate the overlap ratio
    overlap = intersection / union
    
    return overlap
