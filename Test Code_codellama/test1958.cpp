CommandController& CommandCompleter::getGlobalCommandController() {
    // Attempt to cast the commandController to a GlobalCommandController
    GlobalCommandController* globalController = dynamic_cast<GlobalCommandController*>(commandController);
    if (globalController != nullptr) {
        return *globalController;
    }

    // If the cast fails, fall back to using checked_cast to cast the commandController to an MSXCommandController
    MSXCommandController* msxController = checked_cast<MSXCommandController*>(commandController);
    if (msxController != nullptr) {
        return msxController->getGlobalCommandController();
    }

    // If the cast fails again, throw an exception
    throw std::runtime_error("Failed to retrieve global command controller");
}
