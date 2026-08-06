#include <iostream>
using namespace std;
int main(){
    int C, N;
    cin >> C >> N;
    int prices[20];
    for(int i=0;i<N;i++) cin >> prices[i];
    int count=0;
    for(int mask=0; mask < (1<<N); mask++){
        int sum=0;
        for(int i=0;i<N;i++){
            if(mask & (1<<i)) sum += prices[i];
        }
        if(sum==C) count++;
    }
    cout << count << endl;
    return 0;
}
