String IPFlowID::unparse() {
    // Extract the IP flow ID from the internal representation
    // stored in the tmp array
    String ipFlowID;
    for (int i = 0; i < 64; i++) {
        if (tmp[i] == '\0') {
            break;
        }
        ipFlowID += tmp[i];
    }
    return ipFlowID;
}
