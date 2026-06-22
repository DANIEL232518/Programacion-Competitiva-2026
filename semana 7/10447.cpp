//Bryan Joseph Huanca Supo
//Pari Valencia Jhon Daniel
//Quispe Perez Cristofer Dex
#include<iostream>
using namespace std;

int main(){
    int n=0,q=0;
    cin>>n>>q;
    int canicas[n];
    int queries[q];
    for(int i=0;i<n;i++){
        cin>>canicas[i];
    }
    for(int i=0;i<q;i++){
        cin>>queries[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            int temp = 0;
            if (canicas[j] > canicas[j + 1]) {
                temp = canicas[j + 1];
                canicas[j + 1] = canicas[j];
                canicas[j] = temp;
            }
        }
    }
    for(int i=0;i<n;i++) {
        cout<<canicas[i];
    }

}