import os
import pickle

def process_linguistic_data(output_dir, workdir, cleared_corpus_path):
    # Extract known predicates from the file 'features.pckl'
    with open(os.path.join(output_dir, 'features.pckl'), 'rb') as f:
        ling_data = pickle.load(f)

    # Print the message
    print('Generating the model for unknown predicates********************************')

    # Create a subdirectory named 'unknown_preds' within the `workdir`
    unknown_preds_dir = os.path.join(workdir, 'unknown_preds')
    if not os.path.exists(unknown_preds_dir):
        os.makedirs(unknown_preds_dir)

    # Call a function `work_with_one_model`
    work_with_one_model(cleared_corpus_path, ling_data, unknown_preds_dir)

# This function is not defined in the provided code snippet.
# It is assumed that this function is defined elsewhere in the code.
def work_with_one_model(cleared_corpus_path, ling_data, unknown_preds_dir):
    pass

# Call the function from the main block of a Python script
if __name__ == "__main__":
    output_dir = '/path/to/output/dir'
    workdir = '/path/to/workdir'
    cleared_corpus_path = '/path/to/cleared/corpus'
    process_linguistic_data(output_dir, workdir, cleared_corpus_path)