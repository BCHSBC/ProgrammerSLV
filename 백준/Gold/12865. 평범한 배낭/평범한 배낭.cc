#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n,k;
int w[101];
int v[101];
int Best[101][100001];
int get(int idx, int last){
    if(idx == n+1){
        return 0;
    }
    int &res = Best[idx][last];
    if(res != -1) return res;
    
    if(last - w[idx]>=0) {
        res = get(idx+1,last-w[idx]) + v[idx];
    }
    res = max(res,get(idx+1,last));
    
    return res;
}
int main() {
    cin >> n >> k;
    /*for(int i = 0;i<101;i++){
        for(int j = 0;j<100001;j++){
            Best[i][j] = -1;
        }
    }*/
    for(int i = 1;i<=n;i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 1;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(j<w[i]) {
                Best[i][j] = Best[i-1][j];
            } else {
                Best[i][j] = max(Best[i-1][j],Best[i-1][j-w[i]]+v[i]);
            }
        }
    }
    cout << Best[n][k];
    
}