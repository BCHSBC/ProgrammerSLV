#include <iostream>
using namespace std;
int main() {
    int a,b;
    cin >> a >> b;
    int x = a * (b%10);
    int y = a * ((b%100)/10);
    int z = a * (b/100);
    cout << x << "\n" << y << "\n" << z << "\n" << x+10*y+100*z;
}