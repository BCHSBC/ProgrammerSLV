#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
string str;
string bomb;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    cin >> bomb;
    deque <string> dq;
    for(int i = 0;i<str.length();i++){
        string s ="";
        s += str[i];
        dq.push_back(s);
        string tmp = "";
        for(int k = dq.size()-1;k>= dq.size()-bomb.length()&&k>=0;k--){
            tmp = dq[k] + tmp;
        }
        if(bomb == tmp){
            for(int k = 0;k<bomb.length();k++){
                dq.pop_back();
            }
        }
    }
    if(dq.size() == 0) cout << "FRULA";
    else {
        string ans = "";
        while(dq.size() > 0){
            ans += dq.front();
            dq.pop_front();
        }
        cout << ans;
    }
}

