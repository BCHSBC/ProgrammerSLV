#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string a,b,str="";
    cin >>a >> b;
    if(a.length() < b.length()){
        string c;
        c = a;
        a = b;
        b = c;
    }
    while(a.length()!=b.length()){
        b = "0"+b;
    }
    bool flag = false;
    for(int i = b.length()-1;i>=0;i--){
        if(flag) {
            int na = a[i]-'0';
            int nb = b[i]-'0';
            int sum = na+nb+1;
            if(sum>=10) {
                flag = true;
                str = to_string(sum-10) + str;
            } else {
                flag = false;
                str = to_string(sum) + str;
            }
        } else {
            int na = a[i]-'0';
            int nb = b[i]-'0';
            int sum = na+nb;
            if(sum>=10) {
                flag = true;
                str = to_string(sum-10) + str;
            } else {
                str = to_string(sum) + str;
            }
        }
    }
    if(a.length()==b.length()){
        if(flag)
            cout << 1 << str;
        else 
            cout << str;
    }
}