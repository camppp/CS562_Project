import nibabel as nib
import numpy as np

def process_nifti_image(scan_nii, min_, max_):
    # Clip the intensity values of the image array
    scan_nii = np.clip(scan_nii, min_, max_)
    return scan_nii

if __name__ == "__main__":
    # Load the NIfTI image
    scan_nii = nib.load('path_to_your_nifti_file.nii')
    scan_id = 'path_to_your_nifti_file.nii'

    # Get the minimum and maximum intensity values
    min_ = np.min(scan_nii.get_fdata())
    max_ = np.max(scan_nii.get_fdata())

    # Process the NIfTI image
    processed_nii = process_nifti_image(scan_nii.get_fdata(), min_, max_)

    # Create a new NIfTI image with the processed data
    processed_img = nib.Nifti1Image(processed_nii, scan_nii.affine)

    # Save the processed NIfTI image
    nib.save(processed_img, 'path_to_save_processed_nifti_file.nii')