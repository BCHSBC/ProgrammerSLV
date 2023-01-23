#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int L[111][111];
bool check[111][111];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    for(int i = 0;i<rectangle.size();i++){
        for(int j = 0;j<4;j++){
            rectangle[i][j] *= 2;
        }
        vector <int> v = rectangle[i];
        for(int x = v[0]; x<= v[2];x++){
            for(int y= v[1];y <= v[3];y++){
                L[x][y] = 1;
            }
        }
    }
    for(int i = 0;i<rectangle.size();i++){
        vector <int> v = rectangle[i];
        for(int x = v[0]+1; x< v[2];x++){
            for(int y= v[1]+1;y < v[3];y++){
                L[x][y] = 0;
            }
        }
    }
    queue <pair<pair<int,int>,int>> q;
    q.push({{characterX,characterY},0});
    check[characterX][characterY] = true;
    while(!q.empty()){
        pair <int,int> p = q.front().first;
        int level = q.front().second;
        q.pop();
        if(p.first == itemX && p.second == itemY){
            answer = level/2;
            break;
        }
        for(int i = 0;i<4;i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(!check[nx][ny] && L[nx][ny] == 1){
                check[nx][ny] = true;
                q.push({{nx,ny},level+1});
            }
        }
    }
    return answer;
}