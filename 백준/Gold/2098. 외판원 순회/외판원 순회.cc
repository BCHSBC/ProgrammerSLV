#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 987654321
int N;
int W[16][16];
int dp[16][1<<16];
int SLV(int node,int visit){
    if(visit+1 == (1<<N)){
        if(W[node][0] == 0) return INF;
        return W[node][0];
    }
    int &res = dp[node][visit];
    if(res != -1) return res;
    res = INF;
    for(int i = 0;i<N;i++){
        if(W[node][i] == 0) continue;
        if((visit & (1<<i))== 0){
            res = min(res,SLV(i,visit | (1<<i))+W[node][i]);
        }
    }
    return res;
}
int main(){
    cin >> N;
    for(int i = 0;i<N;i++){
        for(int j =0;j<N;j++){
            cin >> W[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout << SLV(0,1);
}
