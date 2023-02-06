#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int testCase;
    cin >> testCase;
    while(testCase--){
        int a,b;
        cin >> a >> b;
        cout << 2-a+b << "\n";
    }
}