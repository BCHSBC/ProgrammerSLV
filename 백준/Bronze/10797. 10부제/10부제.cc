#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int dateNum,ans=0;
    cin >> dateNum;
    for(int i = 0;i<5;i++){
        int carNum;
        cin >> carNum;
        if (carNum == dateNum) {
            ans++;
        }
    }
    cout << ans;
}