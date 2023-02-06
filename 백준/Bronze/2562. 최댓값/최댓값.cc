#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int maxnumber = 0;
    int order = 0;
    for(int i = 1;i<=9;i++){
        int num;
        cin >> num;
        if(num > maxnumber) {
            order = i;
            maxnumber = num;
        }
    }
    cout << maxnumber << "\n" << order;
}