int getYAdjustment(BreakableType type) {
    switch (type) {
        case BreakableType::JAR:
            return -9;
        case BreakableType::VASE:
            return -7;
        case BreakableType::CRATE:
            return -12;
        case BreakableType::BARREL:
            return -10;
        default:
            return 0;
    }
}
