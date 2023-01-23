#include <string>
#include <vector>
#include <queue>
using namespace std;
int N;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool check[101][101][101][101];
int L[101][101];
bool POS(int x,int y){
    if(x<0 || x>= N || y <0 || y>= N) return false;
    return true;
}
vector <int> make_vec(int x,int y,int x1,int y1){
    vector <int> a;
    a.push_back(x);
    a.push_back(y);
    a.push_back(x1);
    a.push_back(y1);
    return a;
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    N = board.size();
    for(int i = 0;i<board.size();i++){
        for(int j = 0;j<board[i].size();j++){
            L[i][j] = board[i][j];
        }
    }
    queue <pair<vector<int>,int>> q;
    q.push({make_vec(0,0,0,1),0});
    while(!q.empty()){
        vector <int> p = q.front().first;
        int level = q.front().second;
        q.pop();
        if((p[0] == N-1 && p[1] == N-1 )|| (p[2] == N-1 && p[3] == N-1)){
            answer = level;
            break;
        }
        for(int i = 0;i<4;i++){
            int nx1 = p[0] + dx[i];
            int ny1 = p[1] + dy[i];
            int nx2 = p[2] + dx[i];
            int ny2 = p[3] + dy[i];
            if(POS(nx1,ny1) && POS(nx2,ny2)){
                if(!check[nx1][ny1][nx2][ny2] && L[nx1][ny1] == 0 && L[nx2][ny2] == 0){
                    check[nx1][ny1][nx2][ny2] = true;
                    q.push({make_vec(nx1,ny1,nx2,ny2),level+1});
                }
            }
        }
        if(p[0] == p[2]){
            if(p[0] <N-1){
                if(L[p[0]+1][p[1]] == 0 && L[p[2]+1][p[3]] == 0){
                    if(!check[p[0]+1][p[3]][p[2]][p[3]]){
                        check[p[0]+1][p[3]][p[2]][p[3]] = true;
                        q.push({make_vec(p[0]+1,p[3],p[2],p[3]),level+1});
                    }
                    if(!check[p[0]][p[1]][p[2]+1][p[1]]){
                        check[p[0]][p[1]][p[2]+1][p[1]] = true;
                        q.push({make_vec(p[0],p[1],p[2]+1,p[1]),level+1});
                    }
                }
            }
            if(p[0] >= 1){
                if(L[p[0]-1][p[1]] == 0 && L[p[2]-1][p[3]] == 0){
                    if(!check[p[0]-1][p[3]][p[2]][p[3]]){
                        check[p[0]-1][p[3]][p[2]][p[3]] = true;
                        q.push({make_vec(p[0]-1,p[3],p[2],p[3]),level+1});
                    }
                    if(!check[p[0]][p[1]][p[2]-1][p[1]]){
                        check[p[0]][p[1]][p[2]-1][p[1]] = true;
                        q.push({make_vec(p[0],p[1],p[2]-1,p[1]),level+1});
                    }
                }
            }
        }
        if(p[1] == p[3]){
            if(p[1] <N-1){
                if(L[p[0]][p[1]+1] == 0 && L[p[2]][p[3]+1] == 0){
                    if(!check[p[2]][p[3]+1][p[2]][p[3]]){
                        check[p[2]][p[3]+1][p[2]][p[3]] = true;
                        q.push({make_vec(p[2],p[3]+1,p[2],p[3]),level+1});
                    }
                    if(!check[p[0]][p[1]][p[0]][p[1]+1]){
                        check[p[0]][p[1]][p[0]][p[1]+1] = true;
                        q.push({make_vec(p[0],p[1],p[0],p[1]+1),level+1});
                    }
                }
            }
            if(p[1] >= 1){
                if(L[p[0]][p[1]-1] == 0 && L[p[2]][p[3]-1] == 0){
                    if(!check[p[0]][p[1]][p[0]][p[1]-1]){
                        check[p[0]][p[1]][p[0]][p[1]-1] = true;
                        q.push({make_vec(p[0],p[1],p[0],p[1]-1),level+1});
                    }
                    if(!check[p[2]][p[3]-1][p[2]][p[3]]){
                        check[p[2]][p[3]-1][p[2]][p[3]] = true;
                        q.push({make_vec(p[2],p[3]-1,p[2],p[3]),level+1});
                    }
                }
            }
        }
    }
    return answer;
}