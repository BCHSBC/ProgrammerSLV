#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,K;
int L[11][11];
int ans = 100000;
bool visit[11];
void SLV(int node,int len,int cnt){
    if(len > ans) return ;
    if(cnt == N){
        ans = min(ans,len);
        return;
    }
    for(int i = 0;i<N;i++){
        if(i==node) continue;
        if(visit[i])continue;
        visit[i] = true;
        SLV(i,len+L[node][i],cnt+1);
        visit[i] = false;
    }
}
int main(){
    cin >> N >> K;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin >> L[i][j];
        }
    }
    for(int k=0;k<N;k++){
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                L[i][j] = min(L[i][j],L[i][k]+L[k][j]);
            }
        }
    }
    visit[K] = true;
    SLV(K,0,1);
    cout << ans;
}