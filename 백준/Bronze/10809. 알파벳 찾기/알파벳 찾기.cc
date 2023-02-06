#include <iostream>
#include <string>
using namespace std;
int main() {
    int list[26];
    fill(list,list+26,-1);
    string str;
    cin >> str;
    for(int i = 0;i<str.length();i++){
        if(list[str[i]-97]==-1){
            list[str[i]-97] = i;
        }
    }
    for(int i = 0;i<26;i++){
        cout << list[i] << " ";
    }
}
