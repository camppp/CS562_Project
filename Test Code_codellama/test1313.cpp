string handleError(int errorCode) {
    switch (errorCode) {
        case E_MAX:
            return "Maximum limit reached";
        case E_MIN:
            return "Minimum limit reached";
        case E_INVALID:
            return "Invalid input";
        default:
            return "Unknown error";
    }
}
