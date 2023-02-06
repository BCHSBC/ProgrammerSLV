#include <iostream>
#include <algorithm>
using namespace std;
bool list[10001];
int main() {
    ios::sync_with_stdio(false);
    list[1] = true;
    for(int i = 2;i<=10000;i++){
        for(int j=i+i;j<=10000;j+=i){
            if(list[j]) continue;
            else list[j] = true;
        }
    }
    int M,N,mn=10001,sum=0;
    cin >> M >>N;
    for(int i = M;i<=N;i++){
        if(!list[i]){
            sum += i;
            mn = min(mn,i);
        }
    }
    if(sum == 0) cout << -1;
    else 
    cout << sum << "\n" << mn;
}