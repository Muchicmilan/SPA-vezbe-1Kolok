#include<iostream>
using namespace std;
#define N 4
void printBoard(int tabla[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(tabla[i][j])
                cout << "K" << ' ';
            else
                cout << '_' << ' ';
        }
        cout << endl;
    }
}
bool isValid(int tabla[N][N], int red, int kol) {
    for (int i = 0; i < kol; i++)
        if (tabla[red][i])
            return false;
    for (int i=red, j=kol; i>=0 && j>=0; i--, j--)
        if (tabla[i][j])
            return false;
    for (int i=red, j=kol; j>=0 && i<N; i++, j--)
        if (tabla[i][j])
            return false;
    return true;
}
bool solveNQueen(int tabla[N][N], int kol) {
    if (kol >= N)
        return true;
    for (int i = 0; i < N; i++) {
        if (isValid(tabla, i, kol) ) {
            tabla[i][kol] = 1;
            if ( solveNQueen(tabla, kol + 1))
                return true;
            tabla[i][kol] = 0;
        }
    }
    return false;
}
bool checkSolution() {
    int tabla[N][N];
    for(int i = 0; i<N; i++)
        for(int j = 0; j<N; j++)
            tabla[i][j] = 0;
    if ( solveNQueen(tabla, 0) == false ) {
        cout << "Resenje ne postoji";
        return false;
    }
    printBoard(tabla);
    return true;
}
int main() {
    checkSolution();
}