#include <iostream>
using namespace std;
int main(){
    int wrong[256]={0};
    bool solved[256]={false};
    int solved_count=0, total_time=0;
    int m;
    while(cin >> m && m!=-1){
        char prob;
        char res[10];
        cin >> prob >> res;
        if(solved[prob]) continue;
        if(res[0]=='r'&&res[1]=='i'&&res[2]=='g'&&res[3]=='h'&&res[4]=='t'){
            solved[prob]=true;
            solved_count++;
            total_time += m + 20*wrong[prob];
        } else {
            wrong[prob]++;
        }
    }
    cout << solved_count << " " << total_time << endl;
    return 0;
}
