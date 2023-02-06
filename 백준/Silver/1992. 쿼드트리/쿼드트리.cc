#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n;
int w,b;
int BorW[129][129];
bool check(int x,int y,int len,int flag){
    int cnt = 0;
    for(int i = x;i<x+len;i++){
        for(int j = y;j<y+len;j++){
            if(BorW[i][j] == flag){
                cnt++;
            }
        }
    }
    if(cnt == len*len){
        return true;
    } 
    return false;
}
void Fold(int x,int y,int len){
    if(len == 0) {
        return ;
    }
    if(check(x,y,len,1)){
        cout << "1";
        return;
    }
    if(check(x,y,len,0)){
        cout << "0";
        return;
    }
    cout << "(";
    Fold(x,y,len/2);Fold(x,y+len/2,len/2);Fold(x+len/2,y,len/2);Fold(x+len/2,y+len/2,len/2);
    cout << ")";
    
}

int main() {
    cin >> n;
    for(int i = 0;i<n;i++){
        string str;
        cin >> str;
        for(int j = 0;j<str.length();j++){
            BorW[i][j] = str[j]-'0';   
        }
    }
    Fold(0,0,n);
}