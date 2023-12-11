void handleError(const PotentialSurface& potSurf) {
    if (!potSurf.ok()) {
        showError(ControllerStatus(
            {Origin::Output, ErrType::SetupFailure, VideoStitcherSignalSlots::tr("Panorama snapshot failed").toStdString(), potSurf.status()}));
        return;
    }
    std::string surf = potSurf.release();
}
