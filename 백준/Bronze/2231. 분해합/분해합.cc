#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main(){
    int num;
    cin >> num;
    int c = num;
    int cnt =0;
    while(c >= 1){
        cnt++;
        c/= 10;
    }
    
    int ans=0;
    for(int i = num-9*(cnt);i<=num;i++){
        if(i<=0) continue;
        else {
            int sum = i;
            int tmp = i;
            while(tmp>=1){
                sum += (tmp%10);
                tmp/=10;
            }
            if(sum == num) {
                ans = i;
                break;
            }
        }
    }
    cout << ans;
}