//Bryan Joseph Huanca Supo
//Pari Valencia Jhon Daniel
//Quispe Perez Cristofer Dex
#include<iostream>
using namespace std;

int main(){
    int n = 0, q = 0;
    int caso = 1; // Para llevar la cuenta de los casos de prueba

    // El bucle se repite hasta que N y Q sean 0
    while (cin >> n >> q && (n != 0 || q != 0)) {
        
        // Declaramos los arreglos con el tamaño actual de este caso
        int canicas[n];
        int queries[q];
        
        // 1. Leer las canicas
        for(int i = 0; i < n; i++){
            cin >> canicas[i];
        }
        
        // 2. Leer las consultas (queries)
        for(int i = 0; i < q; i++){
            cin >> queries[i];
        }
        
        // 3. Ordenamiento Burbuja tradicional (Corregido el límite a n-1)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n - 1; j++) { 
                if (canicas[j] > canicas[j + 1]) {
                    int temp = canicas[j + 1];
                    canicas[j + 1] = canicas[j];
                    canicas[j] = temp;
                }
            }
        }
        
        // Imprimir el número de caso actual
        cout << "CASE# " << caso << ":" << endl;
        caso++;
        
        // 4. Búsqueda secuencial para cada consulta
        for(int j = 0; j < q; j++) {
            bool encontrado = false;
            
            for (int i = 0; i < n; i++) {
                if (canicas[i] == queries[j]) {
                    cout << queries[j] << " found at " << (i + 1) << endl;
                    encontrado = true;
                    break; // Salimos del bucle de canicas porque ya encontramos la primera
                }
            }
            
            // Si recorrió todo el arreglo y no cambió la bandera
            if (!encontrado) {
                cout << queries[j] << " not found" << endl;
            }
        }
    }
    
    return 0;
}