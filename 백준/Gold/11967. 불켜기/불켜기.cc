#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N,M;
int L[101][101];
bool check[101][101];
vector <pair<int,int>> V[101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
void reset(){
    for(int i = 1;i<=100;i++){
        for(int j = 1;j<=100;j++){
            check[i][j] = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 0;i<M;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        V[a][b].push_back({c,d});
    }
    L[1][1] = 1;
    int prev = 0;
    int plus = 1;
    while(true){
        queue <pair<int,int>> q;
        q.push({1,1});
        reset();
        bool flag = false;
        check[1][1] = true;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            while(V[p.first][p.second].size()!=0){ // 해당 방에서 킬수있는것들을 킨다
                flag = true;
                pair<int,int> pp = V[p.first][p.second].back();
                L[pp.first][pp.second] = 1;
                V[p.first][p.second].pop_back();
            }
            if(flag) break;
            // 움직일 수 있는 방으로 간다
            for(int i = 0;i<4;i++){
                int nx = p.first + dx[i];
                int ny = p.second + dy[i];
                if(nx <= 0 || nx > N || ny <= 0 || ny > N) continue;
                if(L[nx][ny] == 1 && !check[nx][ny]){
                    q.push({nx,ny});
                    check[nx][ny] = true;
                }
            }
        }
        if(!flag){
            int tmp = 0;
            // 켜져있는 방의 개수에 변화가 있는지 확인
            for(int i = 1;i<=N;i++){
                for(int j = 1;j<=N;j++){
                    if(L[i][j] == 1){
                        tmp++;
                    }
                }
            }
            if(prev == tmp) break;
            else prev = tmp;
        }
    }
    cout << prev;
}