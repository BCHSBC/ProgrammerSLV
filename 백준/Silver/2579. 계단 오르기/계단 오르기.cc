#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int stair[301];
int maxValue[301][2];

int getMaxValue(int idx, int jump, int cnt) {
    if(idx > n){
        return -9999999;
    }
    if(cnt >= 3){
        return -9999999;
    }
    
    int &res = maxValue[idx][jump];
    
    if(res != -1) return res;
    
    if(idx == n) {
        res = stair[idx];
        return res;
    }
    
    int oneUp = getMaxValue(idx+1,0,cnt+1) + stair[idx];
    int twoUp = getMaxValue(idx+2,1,1) + stair[idx];
    
    res = max(oneUp,twoUp);
    
    return res;
}

int main(){
    cin >> n;
    
    for(int i = 0;i<301;i++){
        for(int j = 0;j<2;j++){
            maxValue[i][j] = -1;
        }
    }
    stair[0] = 0;
    for(int i = 1;i<=n;i++){
        cin >> stair[i];
    }
    cout << getMaxValue(0,0,0);
}