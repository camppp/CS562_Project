string generateRouterLogMessage(const string& domain, unsigned int router_id, bool isStopped) {
    string message;
    if (isStopped) {
        message = "[ " + domain + " ][ " + to_string(router_id) + " ]: router stopped.";
    } else {
        message = "[ " + domain + " ][ " + to_string(router_id) + " ]: failed to stop router.";
    }
    return message;
}
