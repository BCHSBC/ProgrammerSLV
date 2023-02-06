#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool check[26];
int main() {
    int testCase;
    cin >> testCase;
    int ans = 0;
    while(testCase--) {
        fill(check,check+26,false);
        string str;
        cin >> str;
        char prev;
        bool flag = true;
        for(int i = 0;i<str.length();i++){
            char c = str[i];
            if(!check[c-97]) {
                prev = c;
                check[c-97] = true;
            } else {
                if(prev == c) {
                    continue;
                } else {
                    flag = false;
                }
            }
        }
        if(flag) {
            ans++;
        }
    }
    cout << ans ;
}