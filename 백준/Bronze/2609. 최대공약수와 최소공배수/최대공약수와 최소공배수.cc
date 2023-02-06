#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;
    int c;
    int preva = a;
    int prevb = b;
    while(b!= 0){
        c = a % b;
        a = b;
        b = c;
    }
    cout << a << "\n" << preva*prevb/a;
}
