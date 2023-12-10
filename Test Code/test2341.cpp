int sum_digits(BigInteger val){
    int sum = 0;
    string valStr = val.toString(); // Assuming the BigInteger class has a method toString() to convert the value to a string
    for (char digit : valStr) {
        if (isdigit(digit)) {
            sum += digit - '0';
        }
    }
    return sum;
}
