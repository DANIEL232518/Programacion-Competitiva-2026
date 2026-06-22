#include <iostream>
using namespace std;
int arr[5];
int n;
int mapas_minimos;
int min_pasos;
// Función manual para verificar si el arreglo está completamente ordenado
bool estaOrdenado() {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}
// Backtracking para explorar las secuencias de intercambios
void buscar(int pasos) {
    // Si ya superamos el mínimo de pasos encontrado previamente, podamos la rama
    if (pasos > min_pasos) {
        return;
    }
    if (estaOrdenado()) {
        if (pasos < min_pasos) {
            min_pasos = pasos;
            mapas_minimos = 1; // Encontramos una nueva longitud mínima global
        } else if (pasos == min_pasos) {
            mapas_minimos++;   // Es otra forma válida con la misma longitud mínima
        }
        return;
    }
    // Intentar simular un intercambio de Bubble Sort en cada posición válida
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            // Intercambio (Swap manual)
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            // Llamada recursiva con el siguiente paso
            buscar(pasos + 1);
            // Deshacer el intercambio (Backtrack)
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
}
int main() {
    int caso_num = 1;
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        // Si ya está ordenado desde el inicio, la salida es directamente 0
        if (estaOrdenado()) {
            cout << "There are 0 swap maps for input data set " << caso_num << "." << 
endl;
        } else {
            mapas_minimos = 0;
            min_pasos = 999999; // Inicializamos con un valor infinito práctico
            buscar(0);
            cout << "There are " << mapas_minimos << " swap maps for input data set " 
<< caso_num << "." << endl;
        }
        caso_num++;
    }
    return 0;
}