#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int L[102][102][2];
bool create(int x,int y,int m){
    if(m == 0){
        if(y == 0) return true;
        if(y > 0 && L[x][y-1][0]) return true;
        if(x < N && L[x][y][1]) return true;
        if(x > 0 && L[x-1][y][1]) return true;
    }else{
        if(y > 0 && L[x][y-1][0]) return true;
        if(y > 0 && x < N && L[x+1][y-1][0]) return true;
        if(x > 0 && x < N && L[x-1][y][1] && L[x+1][y][1]) return true;
    }
    return false;
}
bool remove(int x,int y,int m){
    L[x][y][m] = false;
    if(m == 0){
        if(y < N && L[x][y+1][0] && !create(x,y+1,0)) return false;
        if(x > 0 && y < N && L[x-1][y+1][1] && !create(x-1,y+1,1)) return false;
        if(y < N && L[x][y+1][1] && !create(x,y+1,1)) return false;
    }else{
        if(L[x][y][0] && !create(x,y,0)) return false;
        if(x < N && y < N && L[x+1][y][0] && !create(x+1,y,0)) return false;
        
        if(x > 0 && L[x-1][y][1] && !create(x-1,y,1)) return false;
        if(x < N && L[x+1][y][1] && !create(x+1,y,1)) return false;
    }
    return true;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N = n;
    for(int i = 0;i<build_frame.size();i++){
        vector<int> b = build_frame[i];
        if(b[3] == 0){
            if(!remove(b[0],b[1],b[2])) L[b[0]][b[1]][b[2]] = true;
        }else{
            if(create(b[0],b[1],b[2])) L[b[0]][b[1]][b[2]] = true;
        }
    }
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=n;j++){
            if(L[i][j][0]) answer.push_back({i,j,0});
            if(L[i][j][1]) answer.push_back({i,j,1});
        }
    }
    return answer;
}