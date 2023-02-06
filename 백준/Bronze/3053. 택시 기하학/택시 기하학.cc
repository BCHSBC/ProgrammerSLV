#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    double x;
    const double pi = acos(-1.0);
    cin >> x;
    cout<<fixed;
    cout.precision(6);
    cout << x*x*pi << "\n" << 2*x*x;
}