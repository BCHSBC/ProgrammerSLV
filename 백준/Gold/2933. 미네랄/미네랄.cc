#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int R,C;
int L[101][101];
int N;
bool check[101][101];
bool check2[101][101];
vector <int> stick;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
void HITIT(int h, int turn){ // 뿌시기
    if(turn == 0){
        int lr = 0;
        while(lr < C && L[R-h][lr] == 0){
            lr++;
        }
        L[R-h][lr] = 0;
    }else{
        int rl = C-1;
        while(rl >= 0 && L[R-h][rl] == 0){
            rl--;
        }
        L[R-h][rl] = 0;
    }
}
vector<pair<int,int>> isConnected(int x,int y){ // 땅까지 연결이 되는가?
    check[x][y] = true;
    queue <pair<int,int>> q;
    q.push({x,y});
    vector<pair<int,int>> res;
    bool flag = false;
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        res.push_back(p);
        if(p.first == R-1){
            flag = true;
        }
        for(int i = 0;i<4;i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(!check[nx][ny] && L[nx][ny] == 1){
                check[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
    if(flag) res.push_back({111,111});
    else res.push_back({112,112});
    return res;
}
void resetCheck(){
    for(int i = 0;i<101;i++){
        for(int j = 0;j<101;j++){
            check[i][j] = false;
            check2[i][j] = false;
        }
    }
}
void CHECKBOARD(){
    for(int i = R-1;i>=0;i--){
        for(int j = 0;j<C;j++){
            if(!check[i][j] && L[i][j] == 1){
                vector <pair<int,int>> v = isConnected(i,j);
                vector <pair<int,int>> tmp = v;
                tmp.pop_back();
                vector <pair<int,int>> moved;
                bool flag = false;
                if(v.back().first == 112 && v.back().second == 112){ // 땅에 닫거나 연결되지 않으면 높이를 줄이면서 체크
                    flag = true;
                    v.pop_back();
                    while(true){
                        bool out = false;
                        for(int i = 0;i<v.size();i++){
                            check[v[i].first][v[i].second] = false;
                        }
                        for(int i = 0;i<v.size();i++){
                            v[i].first += 1;
                        }
                        for(int i = 0;i<v.size();i++){
                            // 땅에 닫거나 다른 클러스터(방문하지 않은게 다른거임)와 만난다면
                            if(v[i].first+1 == R || (check[v[i].first+1][v[i].second] &&L[v[i].first+1][v[i].second] == 1)){
                                moved = v;
                                out = true;
                                break;
                            }
                        }
                        if(out) break;
                    }
                }
                v.pop_back();
                if(flag){
                    for(auto e : tmp){
                        L[e.first][e.second] = 0;
                    }
                    for(auto e : moved){
                        L[e.first][e.second] = 1;
                    }
                    return;
                }else{
                    // 땅에 연결된 클러스터는 방문을 초기화
                    
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C;
    for(int i = 0;i < R;i++){
        string str;
        cin >> str;
        for(int j = 0;j < str.length(); j++){
            if(str[j] == '.') L[i][j] = 0;
            else L[i][j] = 1;
        }
    }
    
    cin >> N;
    for(int i = 0;i < N;i++){
        int input;
        cin >> input;
        stick.push_back(input);
    }
    
    for(int i = 0;i < stick.size(); i++){
        int height = stick[i];
        HITIT(height,i%2);
        CHECKBOARD();
        resetCheck();
    }
    for(int i = 0;i<R;i++){
        for(int j = 0;j<C;j++){
            if(L[i][j] == 0) cout << '.';
            else cout << 'x';
        }
        cout << "\n";
    }
}
