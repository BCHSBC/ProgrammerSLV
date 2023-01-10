#include <vector>

using namespace std;

int MOD = 20170805;
int dx[2] = {1,0};
int dy[2] = {0,1};
int dp[501][501][3];
int M,N;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int slv(int x,int y,int direc,vector<vector<int>>& city_map){
    if(x == M-1 && y == N- 1){
        dp[x][y][direc] = 1;
        return dp[x][y][direc];
    }
    if(dp[x][y][direc] != -1) return dp[x][y][direc];
    dp[x][y][direc] = 0;
    
    for(int i = 0;i < 2;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx <0 || nx >= M || ny <0 || ny >= N) continue;
        if(city_map[nx][ny] == 1) continue;
        if(city_map[x][y] == 2 && (direc != i)) continue;
        dp[x][y][direc] = (dp[x][y][direc] + slv(nx,ny,i,city_map)) % 20170805;
    }
    return dp[x][y][direc];
}
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    M = m;
    N = n;
    for(int i = 0;i<501;i++){
        for(int j = 0;j<501;j++){
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;
        }
    }
    answer = slv(0,0,2,city_map);
    return answer;
}