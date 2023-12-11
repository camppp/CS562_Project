def calculate_accuracy(predictions, threshold):
    # Calculate the accuracy based on the threshold
    correct_predictions = [1 for prediction in predictions if prediction > threshold]
    accuracy = sum(correct_predictions) / len(predictions)
    return accuracy

def prepare_validation_data(author):
    # Prepare the validation data for the author
    # This is a placeholder and should be replaced with actual methods
    # related to the author's writing style
    if author == "Poe":
        return [0.8, 0.9, 0.7, 0.6, 0.5]
    elif author == "Tom":
        return [0.4, 0.3, 0.2, 0.1, 0.0]
    else:
        return []

# Test the functions
poe_predictions = prepare_validation_data("Poe")
tom_predictions = prepare_validation_data("Tom")

poe_accuracy = calculate_accuracy(poe_predictions, 0.5)
tom_accuracy = calculate_accuracy(tom_predictions, 0.5)

print(f"Poe's accuracy: {poe_accuracy}")
print(f"Tom's accuracy: {tom_accuracy}")