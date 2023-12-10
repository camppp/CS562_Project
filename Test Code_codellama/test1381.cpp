std::shared_ptr<Node> getNodeByAddress(const std::string& addr) {
    auto foundIter = m_nodesByAddress.find(addr);
    if (foundIter == m_nodesByAddress.end()) {
        return nullptr;
    }
    return foundIter->second->shared_from_this();
}
