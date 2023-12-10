NodeStatus execute() override {
    for (auto child : children) {
        NodeStatus status = child->execute();
        if (status == NodeStatus::Failure) {
            return NodeStatus::Failure;
        }
    }
    return NodeStatus::Success;
}
