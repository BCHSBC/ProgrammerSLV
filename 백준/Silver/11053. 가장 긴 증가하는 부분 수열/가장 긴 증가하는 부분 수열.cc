#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int LIS[1001];
int list[1001];
int main(){
    int n,maxLen=1;
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> list[i];
    }
    for(int i = 1;i<=n;i++){
        LIS[i] = 1;
    }
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            if(list[i] < list[j]) {
                LIS[j] = max(LIS[j],LIS[i]+1);
            }
            maxLen = max(maxLen,LIS[j]);
        }
    }
    cout << maxLen;
}
