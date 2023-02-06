#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    long int N;
    cin >> N;
    long int ans=1;
    for(int i = 1;i<=N;i++){
        ans *= i;
    }
    if(N==0) {
        cout << 1;
    } else {
    cout << ans;
    
    } 
    
}