NodeStatus Sequence::execute() {
    for (auto child : children) {
        NodeStatus status = child->execute();
        if (status == NodeStatus::Failure) {
            return NodeStatus::Failure;
        }
    }
    return NodeStatus::Success;
}
