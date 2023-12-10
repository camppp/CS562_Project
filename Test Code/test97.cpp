void CompositeConnectionListener::removeDelegate(const std::shared_ptr<SmartPtrConnectionListener>& delegate) {
    auto it = std::find(_delegates.begin(), _delegates.end(), delegate);
    if (it != _delegates.end()) {
        _delegates.erase(it);
    }
}

void CompositeConnectionListener::notifyConnectionEvent(const ConnectionEvent& event) {
    for (const auto& delegate : _delegates) {
        delegate->onConnectionEvent(event);
    }
}
