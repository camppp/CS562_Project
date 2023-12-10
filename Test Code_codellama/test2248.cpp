void pivot(matrix& tableau, int& entering_var, int& leaving_var) {
  // Find the pivot element based on the ratio test
  int pivot_row = -1;
  int pivot_col = -1;
  double min_ratio = INFINITY;
  for (int i = 0; i < tableau.size(); i++) {
    for (int j = 0; j < tableau[i].size(); j++) {
      if (tableau[i][j] < 0 && tableau[i][j] < min_ratio) {
        min_ratio = tableau[i][j];
        pivot_row = i;
        pivot_col = j;
      }
    }
  }

  // Perform the row operations to update the tableau
  for (int i = 0; i < tableau.size(); i++) {
    if (i != pivot_row) {
      tableau[i][pivot_col] = tableau[i][pivot_col] / tableau[pivot_row][pivot_col];
      tableau[i][pivot_row] = 0;
    }
  }

  // Update the entering and leaving variables
  entering_var = pivot_col;
  leaving_var = pivot_row;
}
