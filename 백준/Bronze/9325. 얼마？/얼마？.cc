#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int testCase;
    cin >> testCase;
    while(testCase--){
        int carPrice;
        cin >> carPrice;
        int option;
        cin >> option;
        while(option--){
            int q,p;
            cin >> q >> p;
            carPrice += q*p;
        }
        cout << carPrice << "\n";
    }
}