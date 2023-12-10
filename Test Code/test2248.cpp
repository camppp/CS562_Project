void pivotOperation(double** tableau, int enteringVar, int leavingVar, int numRows, int numCols) {
    // Perform row operations to update the tableau
    double pivotElement = tableau[leavingVar][enteringVar];
    
    // Make the pivot element 1
    for (int j = 0; j < numCols; j++) {
        tableau[leavingVar][j] /= pivotElement;
    }
    
    // Make other elements in the pivot column 0
    for (int i = 0; i < numRows; i++) {
        if (i != leavingVar) {
            double pivotCoefficient = tableau[i][enteringVar];
            for (int j = 0; j < numCols; j++) {
                tableau[i][j] -= pivotCoefficient * tableau[leavingVar][j];
            }
        }
    }
}
