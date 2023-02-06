#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

string s;
vector <int> v;
vector <char> c;
int main() {
    cin >> s;
    string str = "";
    for(int i = 0;i<s.length();i++){
        if('0' <= s[i] && s[i] <='9'){
            str += s[i];
        } else {
            v.push_back(stoi(str));
            str = "";
            if(s[i] == '+' || s[i]=='-') c.push_back(s[i]);
        }
    }
    v.push_back(stoi(str));
    int sum = v[0];
    int mc=0;
    bool flag = false;
    for(int i = 0;i<c.size();i++){
        if(c[i] == '-') {
            if(!flag){
                flag = true;
            }
        }
        if(flag == true) {
            c[i] = '-';
        }
        if(c[i] == '+') {
            sum += v[i+1];
        } else {
            sum -= v[i+1];
        }
    }   
    
    cout << sum;
}