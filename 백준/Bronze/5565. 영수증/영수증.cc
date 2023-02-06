#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int sum;
    cin >> sum;
    for(int i = 1;i<10;i++){
        int money;
        cin >> money;
        sum -= money;
    }
    cout << sum;
}