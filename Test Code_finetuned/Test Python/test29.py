import numpy as np
from scipy.stats import pearsonr

def process_differences(pxdiff, pxThreshold, pxCount=None, maxPxDiff=None, avgPxDiff=None, minCorr=None, im1=None, im2=None):
    mask = np.abs(pxdiff) > pxThreshold
    if pxCount is not None:
        assert np.sum(mask) <= pxCount, "Number of pixels exceeding threshold exceeds pxCount"
    if maxPxDiff is not None and np.any(mask):
        assert np.max(pxdiff[mask]) <= maxPxDiff, "Maximum difference exceeds maxPxDiff"
    if avgPxDiff is not None and np.any(mask):
        assert np.mean(pxdiff[mask]) <= avgPxDiff, "Average difference exceeds avgPxDiff"
    if minCorr is not None:
        corr, _ = pearsonr(im1.flatten(), im2.flatten())
        if np.isnan(corr):
            corr = 0
        assert corr >= minCorr, "Correlation coefficient is less than minCorr"