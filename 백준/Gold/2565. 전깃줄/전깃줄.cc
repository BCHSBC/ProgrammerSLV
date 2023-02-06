#include <iostream>
#include <algorithm>
using namespace std;

int n;
int value[501];
int LIS[501];
int main(){
    cin >> n;
    int high = 0;
    int maxLen = 0;
    for(int i = 0;i<501;i++){
        LIS[i] = -1;
    }
    for(int i = 0;i<n;i++){
        int a,b;
        cin >> a >> b;
        value[a] = b;
        LIS[a] = 1;
        high = max(high,b);
    }
    for(int i = 1;i<=high;i++){
        for(int j = i+1;j<=high;j++){
            if(value[i] < value[j]) {
                LIS[j] = max(LIS[j],LIS[i]+1);
            }
            
            maxLen = max(maxLen,LIS[j]);
        }   
    }
    cout << n - maxLen;
}