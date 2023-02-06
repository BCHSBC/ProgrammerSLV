#include <iostream>
using namespace std;
bool list[1001];
int main() {
    ios::sync_with_stdio(false);
    list[1] = true;
    for(int i = 2;i<=1000;i++){
        for(int j=i+i;j<=1000;j+=i){
            if(list[j]) continue;
            else list[j] = true;
        }
    }
    int N,ans=0;
    cin >> N;
    while(N--){
        int num;
        cin >> num;
        if(!list[num]) ans++;
    }
    cout << ans;
}