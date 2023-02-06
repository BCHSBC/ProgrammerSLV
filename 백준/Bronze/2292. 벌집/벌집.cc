#include <iostream>
using namespace std;
int main() {
    int n,cnt = 1;
    cin >> n;
    int number =1;
    while(number < n){
        number += 6*cnt;
        cnt++;
    }
    cout << cnt;
}
