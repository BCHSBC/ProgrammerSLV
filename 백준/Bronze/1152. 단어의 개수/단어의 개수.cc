#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    getline(cin,str);
    int cnt= 0;
    bool word = false;
    for(int i = 0;i<str.length();i++){
        if(str[i]== ' ' && word) {
            cnt++;
            word = false;
        } else {
            word = true;
        }
    }
    if(str[str.length()-1] == ' '){
        cout << cnt;
    } else {
    cout << cnt+1;
    }
    }