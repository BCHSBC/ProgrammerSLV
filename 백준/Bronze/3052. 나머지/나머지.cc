#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    bool list[44];
    fill(list,list+44,false);
    int cnt = 0;
    for(int i = 0;i<10;i++){
        int number;
        cin >> number;
        if(!list[number%42]) {
            cnt++;
            list[number%42] = true;
        }
    }
    cout << cnt;
}