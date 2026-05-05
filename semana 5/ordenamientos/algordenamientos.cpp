#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <string>
using namespace std;
using namespace std::chrono;
struct Estadistica {
    string nombre;
    long long pasos;
    double nanosegundos;
};
long long bubbleSort(vector<int>& arr) {
    long long pasos = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            pasos++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                pasos++;
            }
        }
    }
    return pasos;
}
long long selectionSort(vector<int>& arr) {
    long long pasos = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            pasos++;
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
        pasos++;
    }
    return pasos;
}
void merge(vector<int>& arr, int l, int m, int r, long long& pasos) {
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        pasos++;
        if (L[i] <= R[j]) { arr[k] = L[i]; i++; }
        else { arr[k] = R[j]; j++; }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}
void mergeSort(vector<int>& arr, int l, int r, long long& pasos) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, pasos);
        mergeSort(arr, m + 1, r, pasos);
        merge(arr, l, m, r, pasos);
    }
}
int main() {
    int n, min_r, max_r;
    cout << "Cantidad de numeros: "; cin >> n;
    cout << "Rango (min max): "; cin >> min_r >> max_r;
    vector<int> original(n);
    for (int i = 0; i < n; i++) 
        original[i] = min_r + (rand() % (max_r - min_r + 1));
    cout << "\nArray Generado: ";
    for(int x : original) cout << x << " ";
    cout << "\n";
    vector<Estadistica> resultados;
    auto ejecutar = [&](string nombre, auto funcion, vector<int> data) {
        long long p = 0;
        auto start = high_resolution_clock::now();
        p = funcion(data);
        auto end = high_resolution_clock::now();
        double tiempo = duration_cast<nanoseconds>(end - start).count();
        resultados.push_back({nombre, p, tiempo});
    };
    ejecutar("Bubble Sort", bubbleSort, original);
    ejecutar("Selection Sort", selectionSort, original);
    long long pMerge = 0;
    vector<int> cMerge = original;
    auto sM = high_resolution_clock::now();
    mergeSort(cMerge, 0, n - 1, pMerge);
    auto eM = high_resolution_clock::now();
    resultados.push_back({"Merge Sort", pMerge, (double)duration_cast<nanoseconds>(eM - sM).count()});
    for (int i = 0; i < resultados.size() - 1; i++)
        for (int j = 0; j < resultados.size() - i - 1; j++)
            if (resultados[j].nanosegundos > resultados[j + 1].nanosegundos)
                swap(resultados[j], resultados[j + 1]);
    cout << fixed << setprecision(0);
    cout << "\nPos\tAlgoritmo\tPasos\t\tTiempo (ns)\n";
    for (int i = 0; i < resultados.size(); i++) {
        cout << i + 1 << "\t" << resultados[i].nombre << "\t" 
             << resultados[i].pasos << "\t\t" << resultados[i].nanosegundos << " ns\n";
    }
    return 0;
}
