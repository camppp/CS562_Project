void DispatchCommand(
    FrameworkElement const& view,
    winrt::hstring const& commandId,
    winrt::IJSValueReader const& commandArgsReader) noexcept {

    if (auto module = view.try_as<winrt::RCTPdf::RCTPdfControl>()) {
        module.DispatchCommand(commandId, commandArgsReader);
    }
}
