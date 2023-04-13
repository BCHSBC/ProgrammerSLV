#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool check[65][65];
int N,Q;
int A[65][65];
vector <int> Q_input;
int total_sum = 0;
int A_len;
int max_sum = 0;
void BFS(int x,int y){
    check[x][y] = true;
    queue <pair<int,int>> q;
    q.push({x,y});
    int cur_sum = 0;
    while(!q.empty()){
        pair <int,int> p = q.front();
        q.pop();
        total_sum += A[p.first][p.second];
        cur_sum++;
        for(int i = 0;i<4;i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(nx < 0 || nx >= A_len || ny < 0 || ny >= A_len) continue;
            if(!check[nx][ny] && A[nx][ny] >= 1){
                check[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
    if(cur_sum>= 2){
        max_sum = max(max_sum,cur_sum);
    }
    return ;
}

int main() {

    cin >> N >> Q;
    for(int i =  0;i<(int)pow(2,N);i++){
        for(int j = 0;j<(int)pow(2,N);j++){
            cin >> A[i][j];
        }
    }
    A_len = (int)pow(2,N);
    int tmp;
    for(int k = 0;k<Q;k++){
        cin >> tmp;
        for(int i = 0;i<A_len;i+= (int)pow(2,tmp)){
            for(int j = 0;j<A_len;j+= (int)pow(2,tmp)){
                // This is for rotating arrays
                int len = (int)pow(2,tmp);
                int **arr = new int*[len];
                int **arr2 = new int*[len];
                for(int x = 0;x<len;x++){
                    arr[x] = new int[len];
                    arr2[x] = new int[len];
                }

                for(int x = 0;x<len;x++){
                    for(int y = 0;y<len;y++){
                        arr[x][y] = A[x+i][y+j];
                    }
                }
                for(int x = 0;x<len;x++){
                    for(int y = 0;y<len;y++){
                        arr2[x][y] = arr[len-y-1][x];
                    }
                }
                for(int x = 0;x<len;x++){
                    for(int y = 0;y<len;y++){
                        A[x+i][y+j] = arr2[x][y];
                    }
                }    
                for(int x = 0;x<len;x++){
                    delete[] arr[x];
                    delete[] arr2[x];
                }
                delete[] arr;
                delete[] arr2;
                //--------------------------
            }
        }
        for(int i = 0;i<A_len;i++){
            for(int j = 0;j<A_len;j++){
                if(A[i][j] == 0) continue;
                int _count = 0;
                check[i][j] = false;
                for(int k = 0;k<4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx>=0 && nx < A_len && ny >=0 && ny <A_len && A[nx][ny] != 0){
                        _count++;
                    }
                }
                if(_count < 3){
                    check[i][j] = true;
                }
            }
        }
        for(int i = 0;i<A_len;i++){
            for(int j = 0;j<A_len;j++){
                if(check[i][j] && A[i][j] >= 1){
                    A[i][j]--;
                }
            }
        }
    }
    for(int i = 0;i<A_len;i++){
        for(int j = 0;j<A_len;j++){
            check[i][j] = false;
        }
    }
    for(int i = 0;i<A_len;i++){
        for(int j = 0;j<A_len;j++){
            if(!check[i][j] && A[i][j] != 0){
                BFS(i,j);
            }
        }
    }
    cout << total_sum << "\n" << max_sum;
}