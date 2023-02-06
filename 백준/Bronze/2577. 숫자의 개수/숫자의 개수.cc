#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    int list[10];
    fill(list,list+10,0);
    int A,B,C;
    cin >> A >> B >> C;
    int multiple = A*B*C;
    while(multiple >= 1) {
        list[multiple%10]++;
        multiple/=10;
    }
    for(int i = 0;i<=9;i++){
        cout << list[i] << "\n";
    }
}