#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
string from,to,tmp;
int ans = 987654321;
void change(int idx){
    if(from[idx] == '0') from[idx] = '1';
    else from[idx] = '0';
}
void SLV(int idx,int cnt){
    if(from == to){
        ans = min(ans,cnt);
    }
    if(idx >= N) return;
    
    if(from[idx-1] == to[idx-1]){
        SLV(idx+1,cnt);
    }
    else{
        change(idx-1);
        change(idx);
        if(idx < N-1) change(idx+1);
        SLV(idx+1,cnt+1);
    }
}
int main()
{
    cin >> N;
    cin >> from;
    cin >> to;
    tmp = from;
    SLV(1,0);
    from = tmp;
    change(0);
    change(1);
    SLV(1,1);
    if(ans == 987654321) cout << -1;
    else cout << ans;
}