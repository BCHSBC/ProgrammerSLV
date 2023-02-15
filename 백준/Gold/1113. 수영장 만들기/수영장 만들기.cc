#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int N,M;
int H[51][51];
int nH[51][51];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int POUR(int i,int j,int h){
    queue <pair<int,int>> q;
    q.push({i,j});
    bool check[51][51];
    for(int i = 0;i<51;i++){
        for(int j=0;j<51;j++){
            check[i][j] = false;
        }
    }
    int sum = 0;
    sum += h - H[i][j];
    vector <pair<int,int>> v;
    v.push_back({i,j});
    check[i][j]= true;
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
                    
        for(int x = 0;x<4;x++){
            int nx = p.first + dx[x];
            int ny = p.second + dy[x];
            if(nx <0 || nx >= N || ny < 0 || ny >= M){
                return -1;
            }
            if(!check[nx][ny] && H[nx][ny] < h){
                sum += h - H[nx][ny];
                v.push_back({nx,ny});
                check[nx][ny] = true;
                q.push({nx,ny});
            }
            
        }
    }
    for(auto p : v){
        nH[p.first][p.second] = h;   
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ans = 0;
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        string str;
        cin >> str;
        for(int j=0;j<str.length();j++){
            H[i][j] = str[j]-'0';
        }
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            int prev = 0;
            if(nH[i][j] != 0) continue;
            for(int h = H[i][j]+1;h<=9;h++){
                if(POUR(i,j,h) == -1){
                    break;
                }
            }
        }
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(nH[i][j] !=0){
                ans += nH[i][j] - H[i][j];
            }
        }
    }
    cout << ans;
}