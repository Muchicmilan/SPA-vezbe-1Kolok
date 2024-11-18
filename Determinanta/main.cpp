#include <iostream>
#include <cmath>
using namespace std;

void eliminacijaPoKoloni(int n, double matrix[][100], int trenRed, int trenKol, double matrix2[][100]) {
    int a = 0;
    for (int i = 0; i < n; i++) {
        if (i == trenRed) continue;
        int b = 0;
        for (int j = 0; j < n; j++) {
            if (j == trenKol) continue;
            matrix2[a][b] = matrix[i][j];
            b++;
        }
        a++;
    }
}

double determinant(int n, double matrix[][100]) {
    if (n == 1) return matrix[0][0];
    if (n == 2)
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    double det = 0;
    double matrix2[100][100];
    for (int i = 0; i < n; i++) {
        eliminacijaPoKoloni(n, matrix, 0, i, matrix2);
        det += matrix[0][i] * pow(-1, i) * determinant(n - 1, matrix2);
    }
    return det;
}

int main() {
    int n = 4;
    double matrix[100][100] = {
        {1, 3, 5, 2},
        {4, 1, 7, 1},
        {1, 4, 2, 7},
        {9, 4, 8, 1}
    };
    cout << "Determinanta: " << determinant(n, matrix) << endl;
    return 0;
}