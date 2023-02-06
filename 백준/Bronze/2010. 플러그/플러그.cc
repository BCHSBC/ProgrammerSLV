#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int plug;
    cin >> plug;
    int sum=1;
    while(plug--){
        int multi;
        cin >> multi;
        sum += (multi-1);
    }
    cout << sum;
}