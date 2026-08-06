#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
}

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);
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
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n, min_r, max_r;
    cout << "Cantidad de numeros: "; cin >> n;
    cout << "Rango (min max): "; cin >> min_r >> max_r;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = min_r + (rand() % (max_r - min_r + 1));

    cout << "\nArray Generado: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    vector<int> c1 = arr, c2 = arr, c3 = arr;

    bubbleSort(c1);
    selectionSort(c2);
    mergeSort(c3, 0, n - 1);

    cout << "\nBubble Sort:    ";
    for (int x : c1) cout << x << " ";
    cout << "\nSelection Sort: ";
    for (int x : c2) cout << x << " ";
    cout << "\nMerge Sort:     ";
    for (int x : c3) cout << x << " ";
    cout << "\n";

    return 0;
}
