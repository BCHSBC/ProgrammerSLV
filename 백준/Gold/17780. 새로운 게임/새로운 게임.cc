#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N,K;
vector<pair<int,int>> M[13][13];
int B[13][13];
vector<pair<int,int>> ML;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
bool flag = false;
void MOVE(int x,int y,int direc,int cnt){
    int nx = x + dx[direc-1];
    int ny = y + dy[direc-1];
    
    // 보드판을 넘어가는 경우 파란색으로 작동
    if(nx <= 0 || nx > N || ny <= 0 || ny > N){
        if(cnt ==0){
                if(direc == 1) {
                    M[x][y][0].second = 2;
                    MOVE(x,y,2,1);
                }
                if(direc == 2) {
                    M[x][y][0].second = 1;
                    MOVE(x,y,1,1);
                }
                if(direc == 3) {
                    M[x][y][0].second = 4;
                    MOVE(x,y,4,1);
                }
                if(direc == 4) {
                    M[x][y][0].second = 3;
                    MOVE(x,y,3,1);
                }
        }else{
            return;
        }
    }else{
        // 이동하고자 하는 보드판이 흰색일 경우
        if(B[nx][ny] == 0){
            for(auto t : M[x][y]){
                ML[t.first] = {nx,ny}; // 해당 말의 위치를 바꾼다
                M[nx][ny].push_back(t);
            }
            if(M[nx][ny].size() >= 4) flag = true;
            M[x][y].clear();
        }
        
        // 이동하고자 하는 보드판이 빨간색일 경우
        if(B[nx][ny] == 1){
            reverse(M[x][y].begin(),M[x][y].end()); // 뒤집어 주기
            for(auto t : M[x][y]){
                ML[t.first] = {nx,ny}; // 해당 말의 위치를 바꾼다
                M[nx][ny].push_back(t);
            }
            if(M[nx][ny].size() >= 4) flag = true;
            M[x][y].clear();
        }
        
        // 이동하고자 하는 보드판이 파란색일 경우
        if(B[nx][ny] == 2){
            if(cnt ==0){
                if(direc == 1) {
                    M[x][y][0].second = 2;
                    MOVE(x,y,2,1);
                }
                if(direc == 2) {
                    M[x][y][0].second = 1;
                    MOVE(x,y,1,1);
                }
                if(direc == 3) {
                    M[x][y][0].second = 4;
                    MOVE(x,y,4,1);
                }
                if(direc == 4) {
                    M[x][y][0].second = 3;
                    MOVE(x,y,3,1);
                }
            }else{
                return;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> K;
    
    // 보드판 상태 입력 받기
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            cin >> B[i][j];
        }
    }
    
    // 말 상태 입력 받기
    for(int i = 0;i<K;i++){
        int x,y,d;
        cin >> x >> y >> d;
        M[x][y].push_back({i,d});
        ML.push_back({x,y});
    }
    
    int turn = 1;
    while(turn <= 1000){
        for(int i = 0;i<ML.size();i++){
            pair<int,int> loc = ML[i];
            
            // 내가 이동하고자 하는 말이 제일 아래에 있을 때
            if(!M[loc.first][loc.second].empty() && M[loc.first][loc.second][0].first == i){
                MOVE(loc.first,loc.second,M[loc.first][loc.second][0].second,0);
            }
            if(flag){
                break;
            }
        }
        if(flag){
            break;
        }
        turn++;
    }
    if(flag) cout << turn;
    else cout << -1;
    
    return 0;
}