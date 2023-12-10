GlobalCommandController& CommandCompleter::getGlobalCommandController() const {
    if (auto globalCommandController = dynamic_cast<GlobalCommandController*>(&commandController)) {
        return *globalCommandController;
    } else {
        return checked_cast<MSXCommandController*>(&commandController)->getGlobalCommandController();
    }
}
