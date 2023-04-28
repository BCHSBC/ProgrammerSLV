#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321
int T;
int K;
int dp[501][501];
int sum[501];
int cost[501];
int SLV(int tx,int ty){
    if(dp[tx][ty] != INF) return dp[tx][ty];
    
    if(tx == ty){
        return dp[tx][ty] = 0;
    }
    if(tx + 1 == ty){
        return dp[tx][ty] = cost[tx] + cost[ty];
    }
    for(int mid = tx;mid < ty;mid++){
        int left = SLV(tx,mid);
        int right = SLV(mid+1,ty);
        dp[tx][ty] = min(dp[tx][ty],left+right);
    }
    return dp[tx][ty] += sum[ty]-sum[tx-1];
}
int main(){
    cin >> T;
    while(T--){
        cin >> K;
        for(int i =1;i<=K;i++){
            cin >> cost[i];
            sum[i] = sum[i-1] + cost[i];
            for(int j =1;j<=K;j++){
                dp[i][j] = INF;
            }
        }
        cout << SLV(1,K) << "\n";
    }
}
