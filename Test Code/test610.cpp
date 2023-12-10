Tristate& operator=(bool const aValue) {
    if (aValue) {
        mValue = True;
    } else {
        mValue = False;
    }
    return *this;
}
