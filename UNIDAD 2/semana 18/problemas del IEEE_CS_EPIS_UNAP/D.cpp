#include <iostream>
using namespace std;
int main(){
    char line[205];
    cin >> line;
    int a=0, b=0;
    int i=0;
    while(line[i] != '\0'){
        char player=line[i];
        int puntos=line[i+1]-'0';
        if(player=='A') a += puntos;
        else b += puntos;
        i += 2;
        if(a>=11 && a-b>=2){
            cout << "A" << endl;
            return 0;
        }
        if(b>=11 && b-a>=2){
            cout << "B" << endl;
            return 0;
        }
    }
    if(a>b) cout << "A" << endl;
    else cout << "B" << endl;
    return 0;
}
