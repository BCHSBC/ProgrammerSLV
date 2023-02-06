#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int a,b,v;
    cin >> a >> b >> v;
    int left = (v-a) %(a-b);
    if(left) {
        cout <<  (v-a)/(a-b) +2;
    } else {
        cout <<  (v-a)/(a-b) +1;
    }
}
