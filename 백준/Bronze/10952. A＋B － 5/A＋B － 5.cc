#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    while(true){
        int a,b;
        cin >> a >> b;
        if(a == 0 && b == 0){
            break;
        }
        cout << a+b << "\n";
    }
}