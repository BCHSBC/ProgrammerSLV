#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int minNum=101;
    int sum = 0;
    for(int i = 1;i<=7;i++){
        int num;
        cin >> num;
        if(num %2 != 0){
            sum += num;
            minNum = min(minNum,num);
        }
    }
    if (sum == 0) cout << -1;
    else {
        cout << sum << "\n" << minNum;
    }
}