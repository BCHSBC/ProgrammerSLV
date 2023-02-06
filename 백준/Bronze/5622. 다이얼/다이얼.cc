#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int t[10] = {11,2,3,4,5,6,7,8,9,10};
char s[10][4] = {{},{},{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','Q','R','S'},{'T','U','V'},{'W','X','Y','Z'}};
int changeToNum(char c) {
    for(int i = 2;i<10;i++){
        for(int j = 0;j<4;j++){
            if(s[i][j] == c) {
                return i+1;
            }
        }
    }
}
int main() {
    string str;
    cin >> str;
    int ans = 0;
    for(int i = 0;i< str.length();i++){
        char c= str[i];
        ans += changeToNum(c);
    }
    cout << ans;
}