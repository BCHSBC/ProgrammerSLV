#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int R,C,K;
char m[6][6];
int ans=0;
bool check[6][6];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
void SLV(int x,int y,int cnt){
    if(cnt > K) return;
    if(x == 1 && y == C && cnt == K){
        ans++;
        return;
    }
    for(int i =0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(x <= 0 || x > R || y <= 0 || y> C) continue;
        if(!check[nx][ny] && m[nx][ny] == '.'){
            check[nx][ny] = true;
            SLV(nx,ny,cnt+1);
            check[nx][ny] = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C >> K;
    for(int i = 1;i<=R;i++){
        for(int j = 1;j<=C;j++){
            cin >> m[i][j];
        }
    }
    check[R][1]= true;
    SLV(R,1,1);
    cout << ans;
}