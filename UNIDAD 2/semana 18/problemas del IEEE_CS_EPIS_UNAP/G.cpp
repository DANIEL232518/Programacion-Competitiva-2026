#include <iostream>
using namespace std;
int a[200005];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    long long inv=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]) inv++;
        }
    }
    cout << inv << endl;
    return 0;
}
