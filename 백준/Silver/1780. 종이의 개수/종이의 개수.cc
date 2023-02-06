#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int w,b;
int BorW[2188][2188];
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
int Fold(int x,int y,int len,int flag){
    if(len == 0) {
        return 0;
    }
    if(check(x,y,len,flag)){
        return 1;
    }
    int res = 0;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            res += Fold(x+i*len/3,y+j*len/3,len/3,flag);
        }
    }
    return res;
}
int main() {
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> BorW[i][j];
        }
    }
    for(int i = -1;i<2;i++){
        cout << Fold(0,0,n,i) << "\n";
    }
}