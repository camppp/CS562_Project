void PnlMnController::updatePreset(Database& dbswdbe, int ixWdbeVPreset, uint jrefTrig, const Sbecore::uint notif) {
    // Check if the preset exists in the database
    if (!dbswdbe->tblwdbeqpreset->loadRecByRef(ixWdbeVPreset, &preset)) {
        throw runtime_error("PnlMnController::updatePreset() - Preset does not exist");
    }

    // Check if the preset is associated with the trigger
    if (preset->jref != jrefTrig) {
        throw runtime_error("PnlMnController::updatePreset() - Preset is not associated with the trigger");
    }

    // Update the preset based on the notification type
    switch (notif) {
        case Sbecore::Notif::TRIG_PRESET_REFRESH:
            // Refresh the preset
            preset->refresh(dbswdbe);
            break;
        case Sbecore::Notif::TRIG_PRESET_UPDATE:
            // Update the preset
            preset->update(dbswdbe);
            break;
        default:
            throw runtime_error("PnlMnController::updatePreset() - Unknown notification type");
    }
}
