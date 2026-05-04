#include <iostream>
#include <ctime>
using namespace std;
struct Estadistica {
    string nombre;
    double tiempo;
};
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { arr[k] = L[i]; i++; }
        else { arr[k] = R[j]; j++; }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
    delete[] L; delete[] R;
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main() {
    int n, min_r, max_r;
    cout << "Cantidad de numeros (ej. 10000): "; cin >> n;
    cout << "Rango (min max): "; cin >> min_r >> max_r;
    int* original = new int[n];
    int* copia = new int[n];
    for (int i = 0; i < n; i++) 
        original[i] = min_r + (i % (max_r - min_r + 1));
    Estadistica stats[4];
    for(int i=0; i<n; i++) copia[i] = original[i];
    clock_t t = clock();
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (copia[j] > copia[j+1]) {
                int aux = copia[j]; copia[j] = copia[j+1]; copia[j+1] = aux;
            }
    stats[0] = {"Bubble Sort", (double)(clock() - t) / CLOCKS_PER_SEC};
    for(int i=0; i<n; i++) copia[i] = original[i];
    t = clock();
    for (int i = 0; i < n-1; i++) {
        int m_idx = i;
        for (int j = i+1; j < n; j++) if (copia[j] < copia[m_idx]) m_idx = j;
        int aux = copia[m_idx]; copia[m_idx] = copia[i]; copia[i] = aux;
    }
    stats[1] = {"Selection Sort", (double)(clock() - t) / CLOCKS_PER_SEC};
    for(int i=0; i<n; i++) copia[i] = original[i];
    t = clock();
    for (int i = 1; i < n; i++) {
        int key = copia[i]; int j = i - 1;
        while (j >= 0 && copia[j] > key) { copia[j+1] = copia[j]; j--; }
        copia[j+1] = key;
    }
    stats[2] = {"Insertion Sort", (double)(clock() - t) / CLOCKS_PER_SEC};
    for(int i=0; i<n; i++) copia[i] = original[i];
    t = clock();
    mergeSort(copia, 0, n - 1);
    stats[3] = {"Merge Sort", (double)(clock() - t) / CLOCKS_PER_SEC};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (stats[j].tiempo > stats[j + 1].tiempo) {
                Estadistica temp = stats[j];
                stats[j] = stats[j + 1];
                stats[j + 1] = temp;
            }
        }
    }
    cout.precision(6);
    cout << fixed;
    cout << "\nESTADISTICAS ORDENADAS:\n";
    cout << "----------------------------------------------\n";
    cout << "Algoritmo\t\tTiempo (segundos)\n";
    cout << "----------------------------------------------\n";
    for (int i = 0; i < 4; i++) {
        string tab = (stats[i].nombre.length() < 8) ? "\t\t\t" : "\t\t";
        cout << stats[i].nombre << tab << stats[i].tiempo << " s" << endl;
    }
    delete[] original; delete[] copia;
    return 0;
}