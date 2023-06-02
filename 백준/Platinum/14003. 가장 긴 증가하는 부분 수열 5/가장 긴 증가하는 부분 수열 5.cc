#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
int n;
int input[1000001];
int lis[1000001];
int location[1000001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int cur = 0;
    int number;
    for(int i = 1;i<=n;i++){
        cin >> number;
        input[i] = number;
        if(cur == 0) {
            location[i] = cur;
            lis[cur++] = number;
        }else{
            if(lis[cur-1] < number){
                location[i] = cur;
                lis[cur++] = number;
            }else{
                location[i] =lower_bound(lis,lis+cur,number)-lis;
                lis[lower_bound(lis,lis+cur,number)-lis] = number;
            }
        }
    }
    stack <int> ans;
    cur--;
    for(int i = n;i>=0;i--){
        //cout << location[i] << " " << cur << "\n";
        if(location[i] == cur){
            ans.push(input[i]);
            cur--;
        }
    }
    cout << ans.size() << "\n";
    while(!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
}
