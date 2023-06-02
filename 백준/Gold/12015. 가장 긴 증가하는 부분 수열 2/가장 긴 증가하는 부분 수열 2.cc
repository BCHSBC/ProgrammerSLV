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
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int cur = 0;
    int number;
    for(int i = 1;i<=n;i++){
        cin >> number;
        if(cur == 0) {
            lis[cur++] = number;
        }else{
            if(lis[cur-1] < number){
                lis[cur++] = number;
            }else{
                lis[lower_bound(lis,lis+cur,number)-lis] = number;
            }
        }
    }
    cout << cur;
}
