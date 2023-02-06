#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int x,x1,y,y1,z,z1;
    cin >> x >> x1;
    cin >> y >> y1;
    cin >> z >> z1;
    int ax,ay;
    if(x==y) ax = z;
    else if(x==z) ax =y;
    else ax = x;
    if(x1==y1) ay = z1;
    else if(x1==z1) ay = y1;
    else ay = x1;
    cout << ax << " " << ay;
}