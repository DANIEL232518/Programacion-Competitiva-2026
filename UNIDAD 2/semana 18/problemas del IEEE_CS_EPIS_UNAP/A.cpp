#include <iostream>
using namespace std;
int main(){
    int n[3];
    cin >> n[0] >> n[1] >> n[2];
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            if(n[i]>n[j]){
                int t=n[i]; n[i]=n[j]; n[j]=t;
            }
        }
    }
    char s[4];
    cin >> s;
    for(int i=0;i<3;i++){
        if(s[i]=='A') cout << n[0];
        if(s[i]=='B') cout << n[1];
        if(s[i]=='C') cout << n[2];
        if(i<2) cout << " ";
    }
    cout << endl;
    return 0;
}
