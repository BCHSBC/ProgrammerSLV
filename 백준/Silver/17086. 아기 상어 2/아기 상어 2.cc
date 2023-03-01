#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int N,M;
bool visit[51][51];
int L[51][51];
int T[51][51];
int dx[8] = {-1,1,0,0,-1,1,-1,1};
int dy[8] = {0,0,-1,1,-1,-1,1,1};
vector <pair<int,int>> shark;
int main(){
    cin >> N >> M;
    queue <vector<int>> q;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            cin >> L[i][j];
            if(L[i][j] == 1){
                q.push({i,j,0});
                visit[i][j] = true;
            }
        }
    }
    int ans = 0;
    while(!q.empty()){
        vector <int> vec = q.front();
        q.pop();
        int x = vec[0];
        int y = vec[1];
        int len = vec[2];
        ans = max(ans,len);
        for(int i = 0;i<8;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx <0 || nx >= N || ny < 0 || ny >= M) continue;
            if(visit[nx][ny]) continue;

            visit[nx][ny] = true;
            L[nx][ny] = len+1;
            q.push({nx,ny,len+1});
        }
    }
    cout << ans;
}