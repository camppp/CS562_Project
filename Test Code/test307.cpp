#include <string>

std::string generateRouterLogMessage(const std::string& domain, unsigned int router_id, bool isStopped) {
    if (isStopped) {
        return "[ " + domain + " ][ " + std::to_string(router_id) + " ]: router stopped.";
    } else {
        return "[ " + domain + " ][ " + std::to_string(router_id) + " ]: failed to stop router.";
    }
}
