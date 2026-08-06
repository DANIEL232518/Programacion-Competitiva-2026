#include <iostream>
using namespace std;
int jack[1000005];
int jill[1000005];
int main(){
    int n, m;
    while(cin >> n >> m){
        if(n==0 && m==0) break;
        for(int i=0;i<n;i++) cin >> jack[i];
        for(int i=0;i<m;i++) cin >> jill[i];
        int i=0, j=0, common=0;
        while(i<n && j<m){
            if(jack[i]==jill[j]){
                common++;
                i++; j++;
            } else if(jack[i]<jill[j]){
                i++;
            } else {
                j++;
            }
        }
        cout << common << endl;
    }
    return 0;
}
