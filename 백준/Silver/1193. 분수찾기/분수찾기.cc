#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int x;
    cin >> x;
    int number = 0;
    int cnt = 1;
    while(number < x){
        number += cnt++;
    }
    number -= --cnt;
    int plus = abs(number - x);
    if (cnt%2 == 0) {
        cout << plus << "/" << cnt-plus+1;
    } else {
        cout << cnt-plus+1 << "/" << plus;
    }
}
