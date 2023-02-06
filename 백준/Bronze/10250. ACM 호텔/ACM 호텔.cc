#include <iostream>
using namespace std;
int main() {
    int t,h,w,n;
    cin >> t;
    while(t--) {
        cin >> h >> w >> n;
        if(n%h == 0) {
            cout << h;
            if(n/h>=10){
                cout << n/h;
            } else {
                cout << 0 << n/h;
            }
        } else {
            cout << n%h;
            if(n/h >= 9) {
                cout << n/h+1;
            }else {
                cout <<  0 << n/h+1;
            }
        }
        cout << "\n";
    }
}