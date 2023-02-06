#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int count = 3;
    while(count--) {
        int one,two,three,four;
        cin >> one >> two >> three >> four;
        int sum = 0;
        sum = one + two + three + four;
        switch(sum) {
            case 0:
                cout << "D" << "\n";
                break;
            case 1:
                cout << "C" << "\n";
                break;
            case 2:
                cout << "B" << "\n";
                break;
            case 3:
                cout << "A" << "\n";
                break;
            case 4:
                cout << "E" << "\n";
                break;
            default:
                break;
        }
    }
}