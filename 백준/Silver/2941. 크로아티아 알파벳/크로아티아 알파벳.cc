#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string list[8] = {"c=","c-","dz=","d-","lj","nj","s=","z="};
int main() {
    string str;
    cin >> str;
    int ans = 0;
    int plus = 0;
    for(int i = 0;i<str.length();i+=plus){
        plus = 1;
        for(int j = 0;j<8;j++) {
            string s = list[j];
            if(i+s.length()-1 < str.length() && !str.substr(i,s.length()).compare(s)){
                plus = s.length();
                break;
            }
        }
        ans++;
    }
   cout << ans;
}