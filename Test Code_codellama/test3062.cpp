std::string generateStatusTableRows(const std::vector<Controller>& controllers) {
    std::stringstream out;
    for (const auto& controller : controllers) {
        out << "<tr><td align=left>" << controller.getName() << "<td>";
        if (controller.getForcedLevel() == -1) {
            if (controller.isProfileActive()) {
                out << controller.getProfileID();
            }
            out << "<td>" << std::to_string(controller.getTemperature()) << " C<td>";
        } else {
            out << "<td><td>forced to level " << controller.getForcedLevel();
        }
        if (!controller.working()) {
            out << "[OUT OF FUNCTION] ";
        }
    }
    return out.str();
}
