import numpy as np

def process_batch(batch_x, output):
    # Sample the batch data and output
    preds, nll = sample(batch_x, output)

    # Store the value of nll in a list called nlls
    nlls = [nll]

    # Create a copy of a specific portion of the first row of batch_x
    orig_mask = np.copy(batch_x[0, 4:8])

    # Print the shape of orig_mask
    print("Orig mask", orig_mask.shape)

    # Return the modified batch data and calculated values
    return batch_x, preds, nlls, orig_mask