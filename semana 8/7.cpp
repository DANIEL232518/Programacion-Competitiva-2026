#include <iostream>
using namespace std;
int numeros[5];
int permutacion_actual[5];
bool usado[5];
bool alcanzado;
// Función recursiva para evaluar los 3 operadores (+, -, *) de izquierda a derecha
void evaluarOperadores(int indice, int valor_acumulado) {
    // Si ya logramos el 23 en otra rama, no seguimos buscando
    if (alcanzado) return;
    // Si ya procesamos los 5 números (4 operaciones completadas)
    if (indice == 5) {
        if (valor_acumulado == 23) {
            alcanzado = true;
        }
        return;
    }
    int siguiente_numero = permutacion_actual[indice];
    // Intentar con Suma
    evaluarOperadores(indice + 1, valor_acumulado + siguiente_numero);
    // Intentar con Resta
    evaluarOperadores(indice + 1, valor_acumulado - siguiente_numero);
    // Intentar con Multiplicación
    evaluarOperadores(indice + 1, valor_acumulado * siguiente_numero);
}
// Función recursiva para generar manualmente todas las permutaciones de los 5 números
void generarPermutaciones(int posicion) {
    if (alcanzado) return;
    // Si ya colocamos los 5 números en un orden específico, evaluamos los operadores
    if (posicion == 5) {
        // Iniciamos la evaluación con el primer número como valor acumulado inicial
        evaluarOperadores(1, permutacion_actual[0]);
        return;
    }
    // Probar colocar cada uno de los 5 números de entrada en la posición actual
    for (int i = 0; i < 5; i++) {
        if (!usado[i]) {
            usado[i] = true;
            permutacion_actual[posicion] = numeros[i];
            generarPermutaciones(posicion + 1);
            // Backtrack para liberar el número y probar otra combinación
            usado[i] = false;
        }
    }
}
int main() {
    while (true) {
        int ceros = 0;
        for (int i = 0; i < 5; i++) {
            cin >> numeros[i];
            if (numeros[i] == 0) {
                ceros++;
            }
        }
        // Si los cinco números son 0, terminamos la ejecución del programa
        if (ceros == 5) {
            break;
        }
        alcanzado = false;
        for (int i = 0; i < 5; i++) {
            usado[i] = false;
        }
        // Ejecutar algoritmo de búsqueda exhaustiva
        generarPermutaciones(0);
        if (alcanzado) {
            cout << "Possible" << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}