#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,k;
int answer = 100000001;
int money[11];
void SLV(int sum,int idx,int cnt){
    if(sum == 0){
        answer = cnt;
        cout << cnt;
        exit(0);
    }
    int res = 0;
    if(sum >= money[idx]){
        SLV(sum-money[idx],idx,cnt+1);
    }else {
        SLV(sum,idx-1,cnt);
    }
    

}
int main() {
    cin >> n >> k;
    for(int i = 1;i<=n;i++){
        cin >> money[i];
    }
    SLV(k,n,0);
}