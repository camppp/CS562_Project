void imprimaMatriz(double matriz[LINHAS][COLUNAS]) {
  int j = 0;

  cout << "[" << endl;
  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      cout << matriz[i][j] << " ";
    }
    cout << endl;
  }
  cout << "]" << endl;
}
