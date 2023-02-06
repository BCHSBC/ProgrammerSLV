#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int list[26];
    fill(list,list+26,0);
    string str;
    cin >> str;
    int maxCnt= 0;
    for(int i = 0;i<str.length();i++){
        char c = str[i];
        if((int)c >= 65 && (int)c <= 90){
            list[c-65]++;
            maxCnt = max(maxCnt,list[c-65]);
        } else {
            list[c-97]++;
            maxCnt = max(maxCnt,list[c-97]);
        }
    }
    int cnt = 0;
    int maxI = 0;
    int ans = 0;
    for(int i = 0;i<26;i++){
        if(maxI < list[i]) {
            maxI = list[i];
            ans = i;
        }
         if(maxCnt == list[i]){
            cnt++;
        }
    }
    if(cnt == 1) {
            cout << char('A'+ ans) ;
    } else {
        cout << '?';
    }
}
