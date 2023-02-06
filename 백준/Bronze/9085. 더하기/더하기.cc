#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int testCase;
    cin >> testCase;
    while(testCase--) {
        int count, sum = 0;
        cin >> count;
        while(count--) {
            int number;
            cin >> number;
            sum += number;
        }
        cout << sum << "\n";
    }
}