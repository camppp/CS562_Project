bool operator==(const Device& lhs, const Device& rhs) {
    return lhs.name == rhs.name && lhs.id == rhs.id;
}

bool operator!=(const Device& lhs, const Device& rhs) {
    return !(lhs == rhs);
}

bool operator<(const Device& lhs, const Device& rhs) {
    return lhs.name < rhs.name || (lhs.name == rhs.name && lhs.id < rhs.id);
}
