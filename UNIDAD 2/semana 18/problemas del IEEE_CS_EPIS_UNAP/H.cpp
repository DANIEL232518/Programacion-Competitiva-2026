#include <iostream>
using namespace std;
int R, C;
char grid[1005][1005];
bool visited[1005][1005];
int qr[1000005], qc[1000005];
int main(){
    cin >> R >> C;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            cin >> grid[i][j];
    int islands=0;
    int dr[4]={-1,1,0,0}, dc[4]={0,0,-1,1};
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(grid[i][j]=='1' && !visited[i][j]){
                islands++;
                int head=0, tail=0;
                qr[tail]=i; qc[tail]=j; tail++;
                visited[i][j]=true;
                while(head<tail){
                    int cr=qr[head], cc=qc[head]; head++;
                    for(int d=0;d<4;d++){
                        int nr=cr+dr[d], nc=cc+dc[d];
                        if(nr>=0&&nr<R&&nc>=0&&nc<C && grid[nr][nc]=='1' && !visited[nr][nc]){
                            visited[nr][nc]=true;
                            qr[tail]=nr; qc[tail]=nc; tail++;
                        }
                    }
                }
            }
        }
    }
    cout << islands << endl;
    return 0;
}
