#include <iostream>
#define MAX 9
using namespace std;
// verifica si es seguro colocar un valor en una celda específica
bool esSeguro(int tablero[9][9], int fila, int col, int num) {
    // Comprobar fila
    for (int x = 0; x < 9; x++) {
        if (tablero[fila][x] == num) return false;
    }
    // comprobar columna
    for (int x = 0; x < 9; x++) {
        if (tablero[x][col] == num) return false;
    }
    // comprobar subcuadrícula de 3x3
    int inicioFila = fila - fila % 3;
    int inicioCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i + inicioFila][j + inicioCol] == num) return false;
        }
    }
    return true;
}
// función algorítmica principal utilizando Backtracking recursivo
bool SolucionarSudoku(int tablero[9][9]) {
    int fila = -1;
    int col = -1;
    bool vacio = true;
    // encontrar la primera celda que contenga un 0 (celda libre)
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (tablero[i][j] == 0) {
                fila = i;
                col = j;
                vacio = false;
                break;
            }
        }
        if (!vacio) break;
    }
    // caso base: Si no quedan celdas vacías, el Sudoku está resuelto correctamente
    if (vacio) return true;
    // ciclo de ramificación para probar dígitos del 1 al 9
    for (int num = 1; num <= 9; num++) {
        if (esSeguro(tablero, fila, col, num)) {
            // asignación tentativa (descenso en el árbol de recursión)
            tablero[fila][col] = num;
            // evaluar de manera recursiva el subárbol resultante
            if (SolucionarSudoku(tablero)) return true;
            // si falla la asignación intermedia, se aplica Backtracking (limpieza de estado)
            tablero[fila][col] = 0;
        }
    }
    // retorna false si ninguna rama numérica de este nodo es viable
    return false;
}
void Imprimir(int tablero[9][9]) {
    for (int fila = 0; fila < 9; fila++) {
        if (fila % 3 == 0 && fila != 0) {
            cout << "------+-------+------" << endl;
        }
        for (int col = 0; col < 9; col++) {
            if (col % 3 == 0 && col != 0) {
                cout << "| ";
            }
            cout << tablero[fila][col] << " ";
        }
        cout << endl;
    }
}
int main() {
    // redirección de lectura desde archivo de entrada según la plantilla provista
    freopen("in.txt", "r", stdin);
    int tablero[9][9] = {};
    int pos_x, pos_y, valor;
    // lectura dinámica indexando desde 0 internamente
    while (cin >> pos_x >> pos_y >> valor) {
        tablero[pos_x - 1][pos_y - 1] = valor;
    }
    cout << "tablero incial" << endl;
    Imprimir(tablero);
    cout << endl;
    // ejecución y evaluación del resultado
    if (SolucionarSudoku(tablero)) {
        cout << "sudoku solucionado" << endl;
        Imprimir(tablero);
    } else {
        cout << "no se encontro una solucion valida para el tablero ingresado." << endl;
    }
    return 0;
}
