#include <iostream>
using namespace std;

#define LINHAS 2
#define COLUNAS 50

void calculeAreas(double triangulos[LINHAS][COLUNAS], double areas[]) {
  for (int i = 0; i < COLUNAS; i++) {
    areas[i] = (triangulos[0][i] * triangulos[1][i]) / 2;
    cout << "A área do " << i + 1 << "º triângulo é " << areas[i] << endl;
  }
}

void imprimaMatriz(double matriz[LINHAS][COLUNAS]) {
  cout << "[" << endl;
  for (int i = 0; i < LINHAS; i++) {
    cout << "  [";
    for (int j = 0; j < COLUNAS; j++) {
      cout << matriz[i][j];
      if (j < COLUNAS - 1) {
        cout << ", ";
      }
    }
    cout << "]" << endl;
  }
  cout << "]" << endl;
}

int main() {
  double triangulos[LINHAS][COLUNAS] = {{3, 4, 5}, {7, 8, 9}};
  double areas[COLUNAS];

  cout << "Matriz de Triângulos:" << endl;
  imprimaMatriz(triangulos);

  calculeAreas(triangulos, areas);

  return 0;
}
