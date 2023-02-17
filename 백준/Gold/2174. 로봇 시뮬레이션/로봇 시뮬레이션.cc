#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int A,B,N,M;
vector <vector<int>> loc;
int exist[101][101];
int SWITCH(char d){
    if(d == 'N') return 0;
    if(d == 'W') return 1;
    if(d == 'S') return 2;
    return 3;
}
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
void CHANGED(int idx,char t){
    int d = loc[idx-1][2];
    if(t == 'R'){
        d = d-1;
        if(d < 0) d = 3;
    }else{
        d = (d+1) % 4;
    }
    loc[idx-1][2] = d;
}
int FOWARD(int idx){
    int nx = loc[idx-1][0] + dx[loc[idx-1][2]];
    int ny = loc[idx-1][1] + dy[loc[idx-1][2]];
    if(nx <= 0 || nx > B || ny <= 0 || ny > A) return -1;
    if(exist[nx][ny]){
        return exist[nx][ny];
    }
    exist[loc[idx-1][0]][loc[idx-1][1]] = 0;
    loc[idx-1][0] = nx;
    loc[idx-1][1] = ny;
    exist[nx][ny] = idx;
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B;
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        int x,y;
        char d;
        cin >> x >> y >> d;
        int dd = SWITCH(d);
        loc.push_back({y,x,dd});
        exist[y][x] = i+1;
    }
    bool flag = true;
    for(int i = 0;i<M;i++){
        int robot,repeat=0;
        char t;
        cin >> robot >> t >> repeat;
        while(repeat--){
            if(t == 'L' || t == 'R'){
                CHANGED(robot,t);
            }
            else{
                int res = FOWARD(robot);
                if(res == -1){
                    flag= false;
                    cout << "Robot " << robot << " crashes into the wall";
                    break;
                }else if(res == 0){
                    continue;
                    
                }else{
                    flag=  false;
                    cout << "Robot " << robot << " crashes into robot " << res;
                    break;
                }
            }
        }
        if(!flag) break;
    }
    if(flag) cout << "OK";
}