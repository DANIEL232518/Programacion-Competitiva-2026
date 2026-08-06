#include <iostream>
#include <vector>
using namespace std;
long long fib_memo(int n, vector<long long>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib_memo(n - 1, memo) + fib_memo(n - 2, memo);
    return memo[n];
}
void mostrar_memo(const vector<long long>& memo) {
    cout << "\nTabla DP (memoization):\n";
    for (int i = 0; i < memo.size(); i++) {
        cout << "fib(" << i << ") = " << memo[i] << "\n";
    }
}
int main() {
    int n;
    cout << "n: ";
    cin >> n;
    vector<long long> memo(n + 1, -1);
    memo[0] = 0;
    if (n >= 1) memo[1] = 1;
    long long r = fib_memo(n, memo);
    cout << "Fibonacci(" << n << ") = " << r << "\n";
    mostrar_memo(memo);
    return 0;
}
