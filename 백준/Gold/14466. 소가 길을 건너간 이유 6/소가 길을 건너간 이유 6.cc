#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;

int N,K,R;

bool POS[102][102][102][102];
bool visit[102][102];
bool isCow[102][102];
map <pair<int,int>,int> m;
vector <pair<int,int>> cow;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int cnt = 0;
void BFS(pair<int,int> input){
    for(int i= 0;i<101;i++)
        for(int j = 0;j<101;j++)
            visit[i][j] = false;
    int res = 0;
    queue <pair<int,int>> q;
    q.push(input);
    visit[input.first][input.second] = true;
    while(!q.empty()){
        pair <int,int> p = q.front();
        q.pop();
        
        if(input != p && isCow[p.first][p.second] && (m[input]<m[p])){
            cnt += 1;
        }
        
        for(int i = 0;i<4;i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            
            if(nx <= 0 || nx > N || ny <= 0 || ny > N)continue;
            if(POS[nx][ny][p.first][p.second] || POS[p.first][p.second][nx][ny]) continue;
            if(!visit[nx][ny]){
                visit[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> K >> R;
    for(int i = 0;i<R;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        POS[a][b][c][d] = true;
        POS[c][d][a][b] = true;
    }
    for(int i = 0;i<K;i++){
        int a,b;
        cin >> a >> b;
        cow.push_back({a,b});
        m[{a,b}] = i;
        isCow[a][b] = true;
    }
    for(int i = 0;i<cow.size();i++){
        BFS(cow[i]);
    }
    int answer = K*(K-1)/2 - cnt;
    cout << answer;
}