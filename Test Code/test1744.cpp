namespace cvu {

enum class EBayerCode {
    BG, // GigE Vision Bayer code
    GB, // GigE Vision Bayer code
    RG, // GigE Vision Bayer code
    GR  // GigE Vision Bayer code
};

int bayerCodeGray(EBayerCode code)
{
    switch(code)
    {
    // OpenCV code is shifted one down and one left from
    // the one that GigE Vision cameras are using
    case EBayerCode::BG: return CV_BayerRG2GRAY; // Map GigE Vision BG to OpenCV BayerRG2GRAY
    case EBayerCode::GB: return CV_BayerGR2GRAY; // Map GigE Vision GB to OpenCV BayerGR2GRAY
    case EBayerCode::RG: return CV_BayerBG2GRAY; // Map GigE Vision RG to OpenCV BayerBG2GRAY
    case EBayerCode::GR: return CV_BayerGB2GRAY; // Map GigE Vision GR to OpenCV BayerGB2GRAY
    default: return CV_BayerBG2GRAY; // Default to OpenCV BayerBG2GRAY if the input is not recognized
}
