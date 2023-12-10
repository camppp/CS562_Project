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
    case EBayerCode::BG: return CV_BayerGR2GRAY;
    case EBayerCode::GB: return CV_BayerBG2GRAY;
    case EBayerCode::RG: return CV_BayerGB2GRAY;
    case EBayerCode::GR: return CV_BayerRG2GRAY;
    default: return CV_BayerBG2GRAY;
}
