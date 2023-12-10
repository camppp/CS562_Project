vector<double> performOperations(vector<double> div, int offset, double n, int VERB) {
    for (int ix = 0; ix < div.size(); ix++) {
        if (div[ix] <= 0 || n == 0) {
            div[ix] = 1.0;
        } else {
            div[ix] = sqrt(div[ix] / n);
        }
        if (VERB > 2) {
            cout << "Value at index " << offset + ix << ": " << div[ix] << endl;
        }
    }
    return div;
}
