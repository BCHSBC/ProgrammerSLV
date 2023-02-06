#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int sum = 0;
    for(int i = 1;i<=5;i++){
        int num;
        cin >> num;
        sum += (num*num)%10;
    }
    cout << sum %10;
}