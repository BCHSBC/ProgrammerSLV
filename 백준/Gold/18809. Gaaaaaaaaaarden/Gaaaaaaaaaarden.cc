#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N,M,R,G;
int L[51][51];
vector <pair<int,int>> v;
vector <int> GG,RR;
bool vcheck[11];
struct Node{
    int color;
    int t;
} LL[51][51];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int ans = 0;
int slv2(){
    int res = 0;
    memset(LL,-1,sizeof(LL));
    queue <pair<int,int>> q;
    for(int i = 0;i<GG.size();i++){
        LL[v[GG[i]].first][v[GG[i]].second] = {0,0};
        q.push(v[GG[i]]);
    }
    for(int i = 0;i<RR.size();i++){
        LL[v[RR[i]].first][v[RR[i]].second] = {1,0};
        q.push(v[RR[i]]);
    }
    while(!q.empty()){
        pair <int,int> p = q.front();
        int c = LL[p.first][p.second].color;
        int tt = LL[p.first][p.second].t;
        q.pop();
        if(LL[p.first][p.second].color == 3) continue;
        for(int i = 0;i<4;i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(nx <0 || nx >= N || ny < 0 || ny >= M) continue;
            if(L[nx][ny] == 0) continue;
            if(LL[nx][ny].color == -1){
                LL[nx][ny].color = c;
                LL[nx][ny].t = tt+1;
                q.push({nx,ny});
            }else if(LL[nx][ny].color != 3){
                if(LL[nx][ny].color != c && LL[nx][ny].t == tt + 1){
                    LL[nx][ny].color = 3;
                    res++;
                }
            }
        }
    }
    return res;
}
void slv(int idx,int cnt,int g,int r){
    if(cnt > v.size()) return;
    if(g > G) return;
    if(r > R) return;
    if(g == G && r == R) {
        ans = max(ans,slv2());
    }
    for(int i = idx;i<v.size();i++){
        if(!vcheck[i]){
            vcheck[i] = true;
            GG.push_back(i);
            slv(i,cnt+1,g+1,r);
            GG.pop_back();
            RR.push_back(i);
            slv(i,cnt+1,g,r+1);
            RR.pop_back();
            vcheck[i] = false;
        }
    }
}
int main(){
    cin >> N >> M >> G >> R;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            cin >> L[i][j];
            if(L[i][j] == 2){
                v.push_back({i,j});
            }
        }
    }
    slv(0,0,0,0);
    cout << ans;
}