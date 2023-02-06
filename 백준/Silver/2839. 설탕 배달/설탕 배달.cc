#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    int ans = 9999999;
    cin >> n;
    for(int i = 0;i<=n/3;i++){
        int left = n-3*i;
        int plus=  0;
        if(left %5!=0){
            continue;
        } else {
            plus = left / 5;
        }
        ans = min(ans,plus+i);
    }
    if(ans == 9999999)
        cout << -1;
    else
        cout << ans;
}