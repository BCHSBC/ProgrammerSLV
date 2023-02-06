#include <iostream>
#include <algorithm>
using namespace std;
long int multi[46341];
int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int testCase;
    cin >> testCase;
    while(testCase--){
        long int x,y,ans;
        cin >> x >> y;
        long int sub = y-x;
        long int cnt= 1;
        while(cnt*cnt <= sub){
            cnt++;
        }
        cnt--;
        long mu = cnt*cnt;
        if(sub == cnt*cnt)
        {
            ans = 2*cnt-1;
        }else{
        if(sub > cnt*cnt + cnt){
            ans = 2*cnt +1;
        } else{
            ans = 2*cnt;
        }
        }
        cout << ans<<"\n";
    }
}
    /*    1     -1
        11
        111
        121   -4
        1211
        1221
        12211
        12221
        12321  - 9
        123211
        123221
        123321
        1233211
        1234321 -16
        123454321-25
        12345654321-36*/