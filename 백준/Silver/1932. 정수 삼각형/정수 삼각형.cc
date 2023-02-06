#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int maxValue[501][501];
int value[501][501];
int getMaxValue(int level, int idx){
    
    if(level == n){
        return 0;
    }
    
    int &res = maxValue[level][idx];
    
    if(res != -1) return res;
    res = 0;
    res = max(getMaxValue(level+1,idx)+value[level][idx],getMaxValue(level+1,idx+1)+value[level][idx]);

    return res;
}
int main() {
    for(int i = 0;i<501;i++){
        for(int j = 0; j<501;j++){
            maxValue[i][j] = -1;
        }
    }
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin >> value[i][j];
        }
    }
    cout << getMaxValue(0,0);
}