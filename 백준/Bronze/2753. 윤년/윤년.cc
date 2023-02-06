#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int year;
    cin >> year;
    bool check = false;;
    if(year %4 == 0){
        if(year%100!=0 || year%400==0){
            check = true;
        }
    }
    if (check) {
        cout << 1;
    } else {
        cout << 0;
    }
}