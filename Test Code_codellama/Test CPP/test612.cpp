c
void ProcessDenoising(Frame inputFrame)
{
    // Denoise the input frame
    Frame denoisedFrame = Denoise(inputFrame);

    // Update the BatchBuffer and BufferParam arrays
    BatchBuffer[iCurDNIndex] = denoisedFrame;
    BufferParam[iCurDNIndex] = GetBufferParam(denoisedFrame);

    // Increment the current denoise index
    iCurDNIndex = (iCurDNIndex + 1) % VPHAL_DNDI_BUFFERS_MAX;
}
