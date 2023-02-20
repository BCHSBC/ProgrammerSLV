#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int N,K;
vector <pair<int,int>> v(501);
int dp[501][501];
int d[501][501];
int SLV(int node,int jump){
    int &res = dp[node][jump];
    if(res != -1) return res;
    if(node == 1) return 0;
    res = 999999999;
    
    for(int i = 0;i<=jump;i++){
        if(node-i-1 >= 1){
            res = min(res,SLV(node-i-1,jump-i) + d[node-i-1][node]);
        }
    }
    
    return res;
}
int main(){
    cin >> N >> K;
    for(int i = 1;i<=N;i++){
        cin >> v[i].first >> v[i].second;
    }
    for(int i = 0;i<501;i++){
        for(int j= 0;j<501;j++){
            dp[i][j] = -1;
        }
    }
    for(int i = 1;i<N;i++){
        for(int j = i+1;j<=N;j++){
            d[i][j] = abs(v[i].first-v[j].first) + abs(v[i].second-v[j].second);
        }
    }
    cout << SLV(N,K);
}