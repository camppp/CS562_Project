import os
import pickle

def process_linguistic_data(output_dir, workdir, cleared_corpus_path):
    # Extract known predicates from the file 'features.pckl'
    with open(os.path.join(output_dir, 'features.pckl'), 'rb') as f:
        ling_data = pickle.load(f)

    # Print a message indicating the start of the unknown predicate model generation
    print('Generating the model for unknown predicates********************************')

    # Create a subdirectory named 'unknown_preds' within the workdir
    unknown_preds_dir = os.path.join(workdir, 'unknown_preds')
    os.makedirs(unknown_preds_dir, exist_ok=True)

    # Call the work_with_one_model function with the appropriate parameters
    work_with_one_model(cleared_corpus_path, ling_data, unknown_preds_dir)