import numpy as np
import nibabel as nib

def process_nifti_image(scan_nii, min_, max_):
    # Process the NIfTI image and return the processed image
    pass

if __name__ == "__main__":
    scan_id = "../data/Task04_Hippocampus/train/sub-02_ses-01_hippo.nii"
    scan_nii = nib.load(scan_id)
    scan_data = scan_nii.get_fdata()
    min_ = np.min(scan_data)
    max_ = np.max(scan_data)
    processed_scan_data = process_nifti_image(scan_data, min_, max_)
    processed_scan_nii = nib.Nifti1Image(processed_scan_data, scan_nii.affine, scan_nii.header)
    nib.save(processed_scan_nii, "../output/sub-02_ses-0")