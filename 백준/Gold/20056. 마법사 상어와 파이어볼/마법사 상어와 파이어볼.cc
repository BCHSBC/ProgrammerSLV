#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
int N,M,K;
struct FB {
    int w;
    int s;
    int d;
    int time_stamp;
};
queue<FB> LOC[51][51];
vector<FB> TMP[51][51];
int main(){
    cin >> N >> M >> K;
    for(int i = 0;i<M;i++){
        int x,y;
        cin >> x >> y;
        int w,s,d;
        cin >> w >> s >> d;
        LOC[x][y].push({w,s,d,K});
    }
    while(K){
        // 1. move fire ball
        for(int i = 1;i<=N;i++){
            for(int j =0;j<=N;j++){

                while(LOC[i][j].size() > 0){
                    FB fb = LOC[i][j].front();
                    if(fb.time_stamp < K) break;
                    int nx = i + dx[fb.d] * (fb.s%N);
                    int ny = j + dy[fb.d] * (fb.s%N);
                    if(nx <= 0) nx = (N + nx) ;
                    if(ny <= 0) ny = (N + ny) ;
                    if(nx > N) nx = (nx - N) ;
                    if(ny > N) ny = (ny - N) ;
                    LOC[nx][ny].push({fb.w,fb.s,fb.d,fb.time_stamp-1});
                    LOC[i][j].pop();
                }
            }
        }
        // split the fire ball
        for(int i = 1;i<=N;i++){
            for(int j = 1;j<=N;j++){
                if(LOC[i][j].size() >= 2){
                    int wsum=0,ssum=0;
                    int size = LOC[i][j].size();
                    int odd_count = 0;
                    while(!LOC[i][j].empty()){
                        FB fb = LOC[i][j].front();
                        wsum += fb.w;
                        ssum += fb.s;
                        if(fb.d % 2 == 1) odd_count++;
                        LOC[i][j].pop();
                    }
                    int nw = wsum / 5;
                    if(nw == 0) continue;
                    int ns = ssum/size;
                    int start;
                    if(odd_count == size || odd_count == 0){
                        start = 0;
                    }else{
                        start = 1;
                    }
                    for(int p = start;p<=start+6;p+=2){
                        LOC[i][j].push({nw,ns,p,K-1});
                    }
                }
            }
        }
        K--;
    }
    int res = 0;
    for(int i = 1;i<=N;i++){
        for(int j=1;j<=N;j++){
            while(!LOC[i][j].empty()){
                FB fb = LOC[i][j].front();
                LOC[i][j].pop();
                res += fb.w;
            }
        }
    }
    cout << res;
}