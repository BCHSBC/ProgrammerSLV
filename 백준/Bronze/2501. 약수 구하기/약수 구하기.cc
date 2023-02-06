#include <iostream>
#include <algorithm>
using namespace std;
  int list[10001];
int main() {
    ios::sync_with_stdio(false);
    int N,K;
    cin >> N >> K;
    int cnt = 1;
    for(int i = 1;i<= N;i++){
        if(N%i== 0){
            list[cnt++] = i;
        }
    }
    if(K > cnt-1) cout << 0;
    else {
        cout << list[K];
    }
}