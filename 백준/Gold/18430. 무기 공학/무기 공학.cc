#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,M,K;
int L[5][5];
int ans = 0;
bool check[5][5];
void SLV(int x,int y,int sum){
    if(y == M){
        y = 0;
        x++;
        SLV(x,y,sum);
        return ;
    }
    if(x == N){
        ans= max(ans,sum);
        return ;
    }
    if(!check[x][y]){
        if(x + 1 < N && y + 1 < M && !check[x+1][y] && !check[x][y+1]){
            check[x][y] = true;
            check[x+1][y] = true;
            check[x][y+1] = true;
            int tmp = L[x][y]*2 + L[x+1][y] + L[x][y+1];
            SLV(x,y+1,sum+tmp);
            check[x][y] = false;
            check[x+1][y] = false;
            check[x][y+1] = false;
        }
        if(x + 1 < N && y -1 >= 0 && !check[x+1][y] && !check[x][y-1]){
            check[x][y] = true;
            check[x+1][y] = true;
            check[x][y-1] = true;
            int tmp = L[x][y]*2 + L[x+1][y] + L[x][y-1];
            SLV(x,y+1,sum+tmp);
            check[x][y] = false;
            check[x+1][y] = false;
            check[x][y-1] = false;
        }
        if(x -1 >= 0 && y + 1 < M && !check[x-1][y] && !check[x][y+1]){
            check[x][y] = true;
            check[x-1][y] = true;
            check[x][y+1] = true;
            int tmp = L[x][y]*2 + L[x-1][y] + L[x][y+1];
            SLV(x,y+1,sum+tmp);
            check[x][y] = false;
            check[x-1][y] = false;
            check[x][y+1] = false;
        }
        if(x - 1 >= 0 && y - 1 >= 0 && !check[x-1][y] && !check[x][y-1]){
            check[x][y] = true;
            check[x-1][y] = true;
            check[x][y-1] = true;
            int tmp = L[x][y]*2 + L[x-1][y] + L[x][y-1];
            SLV(x,y+1,sum+tmp);
            check[x][y] = false;
            check[x-1][y] = false;
            check[x][y-1] = false;
        }
    }
    SLV(x,y+1,sum);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            cin >> L[i][j];
        }
    }
    SLV(0,0,0);
    cout << ans;
}