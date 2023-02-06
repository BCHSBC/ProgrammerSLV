#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int list[1001][1001];
string str1;
string str2;

int main() {
    cin >> str1;
    cin >> str2;
    int maxLen = 0;
    for(int i =1;i<=str1.length();i++){
        for(int j= 1;j<=str2.length();j++){
            if(str1[i-1] == str2[j-1]) {
                list[i][j] = list[i-1][j-1] +1;
            } else {
                list[i][j] = max(list[i][j-1],list[i-1][j]);
            }
            maxLen = max(maxLen,list[i][j]);
        }
    }
    cout << maxLen;
}