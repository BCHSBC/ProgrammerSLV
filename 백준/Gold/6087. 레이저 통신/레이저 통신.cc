#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int W,H;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int L[101][101];
int sx=-1,sy=-1;
int dp[101][101][4];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> W >> H;
    for(int i = 0;i<H;i++){
        string str;
        cin >> str;
        for(int j = 0;j<str.length();j++){
            for(int x = 0;x<4;x++){
                dp[i][j][x] = 987654321;
            }
            if(str[j] == '*'){
                L[i][j] = 2;
            }
            if(str[j] == 'C'){
                if(sx  == -1){
                    sx = i;
                    sy = j;
                }
                L[i][j] = 1;
            }
        }
    }
    queue <pair<pair<int,int>,int>> q;
    for(int i = 0;i<4;i++){
        dp[sx][sy][i] = 0;
        q.push({{sx,sy},i});
    }
    int ans = 987654321;
    while(!q.empty()){
        pair <int,int> p = q.front().first;
        int d = q.front().second;
        q.pop();
        
        if(L[p.first][p.second] == 1 && (sx!= p.first || sy != p.second)){
            ans = min(ans,dp[p.first][p.second][d]);
            continue;
        }
        
        for(int i =0;i<4;i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(L[nx][ny] == 2) continue;
            if(d != i && dp[nx][ny][i] > dp[p.first][p.second][d] + 1){
                dp[nx][ny][i] = dp[p.first][p.second][d] + 1;
                q.push({{nx,ny},i});
            }
            else if(d == i && dp[nx][ny][i] > dp[p.first][p.second][d]){
                dp[nx][ny][i] = dp[p.first][p.second][d];
                q.push({{nx,ny},i});
            }
        }
    }
    cout << ans;
}