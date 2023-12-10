unsigned long getULong(unsigned long ulo1, unsigned long& ulo2, unsigned long& ulo3) {
    ulo3 = ulo2;
    unsigned long returnedValue = ulo1;
    ulo2 += ulo1 + ulo2;
    return returnedValue;
}
