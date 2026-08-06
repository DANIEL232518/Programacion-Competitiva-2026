#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    cin.ignore(10000, '\n');
    char line[105];
    for(int i=0;i<n;i++){
        cin.getline(line,105);
        if(line[0]=='S'&&line[1]=='i'&&line[2]=='m'&&line[3]=='o'&&line[4]=='n'&&line[5]==' '&&line[6]=='s'&&line[7]=='a'&&line[8]=='y'&&line[9]=='s'&&line[10]==' '){
            cout << (line+11) << endl;
        }
    }
    return 0;
}
