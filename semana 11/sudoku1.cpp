#include <iostream>
using namespace std;

long long contadorPasos = 0;

bool esSeguro(int tablero[9][9], int fila, int col, int num) {
    for (int x = 0; x < 9; x++) {
        if (tablero[fila][x] == num) return false;
    }
    for (int x = 0; x < 9; x++) {
        if (tablero[x][col] == num) return false;
    }
    int inicioFila = fila - fila % 3;
    int inicioCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i + inicioFila][j + inicioCol] == num) return false;
        }
    }
    return true;
}

bool resolverSudoku(int tablero[9][9]) {
    int fila = -1, col = -1;
    bool vacio = true;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (tablero[i][j] == 0) {
                fila = i; col = j; vacio = false; break;
            }
        }
        if (!vacio) break;
    }
    if (vacio) return true;
    for (int num = 1; num <= 9; num++) {
        contadorPasos++;
        if (esSeguro(tablero, fila, col, num)) {
            tablero[fila][col] = num;
            if (resolverSudoku(tablero)) return true;
            tablero[fila][col] = 0;
        }
    }
    return false;
}

void imprimir(int tablero[9][9]) {
    for (int fila = 0; fila < 9; fila++) {
        if (fila % 3 == 0 && fila != 0) cout << "------+-------+------" << endl;
        for (int col = 0; col < 9; col++) {
            if (col % 3 == 0 && col != 0) cout << "| ";
            cout << tablero[fila][col] << " ";
        }
        cout << endl;
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    int tablero[9][9] = {};
    int pos_x, pos_y, valor;
    while (cin >> pos_x >> pos_y >> valor) {
        tablero[pos_x - 1][pos_y - 1] = valor;
    }
    cout << "tablero inicial:" << endl;
    imprimir(tablero);
    cout << endl;
    if (resolverSudoku(tablero)) {
        cout << "tablero final resuelto:" << endl;
        imprimir(tablero);
    } else {
        cout << "no se encontro una solucion valida." << endl;
    }
    return 0;
}
