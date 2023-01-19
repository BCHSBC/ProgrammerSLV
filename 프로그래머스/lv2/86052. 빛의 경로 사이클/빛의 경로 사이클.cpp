#include <string>
#include <vector>
#include <queue>
#include <algorithm>
//#include <iostream>
using namespace std;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
char L[501][501];
bool check[501][501][4];
int realDirec = 0;
int targetX;
int targetY;
int ans = 0;
int N,M;
void reset(){
    ans = 0;
    
    for(int i = 0;i<501;i++){
        for(int j = 0;j<501;j++){
            for(int z = 0;z<4;z++){
                check[i][j][z] = false;
            }
        }
    }
}
int changeDirection(int x,int y,int direc){
    char node = L[x][y];
    switch (node){
        case 'S':
            return direc;
            break;
        case 'L':
            if(direc == 0) return 2;
            if(direc == 1) return 3;
            if(direc == 2) return 1;
            if(direc == 3) return 0;
            break;
        case 'R':
            if(direc == 0) return 3;
            if(direc == 1) return 2;
            if(direc == 2) return 0;
            if(direc == 3) return 1;
            break;
    }
    return -1;
}
void SLV(int x,int y,int direc,int cnt){
    if(cnt > 0){
        if(x == targetX && y == targetY & direc == realDirec){
            ans = cnt;
            return;
        }
    }
    if(check[x][y][direc]) return;
    check[x][y][direc] = true;
    
    int nx = x + dx[direc];
    int ny = y + dy[direc];
    if(nx < 0) nx = N-1;
    if(nx >= N) nx = 0;
    if(ny < 0) ny = M-1;
    if(ny >= M) ny = 0;
    int newDirec;
    newDirec= changeDirection(nx,ny,direc);
    //cout << nx << " " << ny << "\n";
    SLV(nx,ny,newDirec,cnt+1);
}
vector<int> solution(vector<string> grid) {
    N = grid.size();
    M = grid[0].length();
    vector<int> answer;
    for(int i = 0;i<grid.size();i++){
        string str = grid[i];
        for(int j = 0;j<str.length();j++){
            L[i][j] = str[j];
        }
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
           for(int z = 0;z<4;z++){
               if(!check[i][j][z]){
                    ans = 0;
                    realDirec = z;
                    targetX = i;
                    targetY = j;
                    SLV(i,j,z,0);
                    if(ans != 0)
                    answer.push_back(ans);
               }
           } 
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}