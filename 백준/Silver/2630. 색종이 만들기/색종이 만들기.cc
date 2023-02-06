#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int w,b;
int BorW[129][129];
bool check1(int x,int y,int len){
    int cnt = 0;
    for(int i = x;i<x+len;i++){
        for(int j = y;j<y+len;j++){
            if(BorW[i][j] == 1){
                cnt++;
            }
        }
    }
    if(cnt == len*len){
        return true;
    } 
    return false;
}
int Fold(int x,int y,int len){
    if(len == 0) {
        return 0;
    }
    if(check1(x,y,len)){
        return 1;
    }
    return Fold(x,y,len/2) + Fold(x,y+len/2,len/2)+Fold(x+len/2,y,len/2) + Fold(x+len/2,y+len/2,len/2);
}
bool check2(int x,int y,int len){
    int cnt = 0;
    for(int i = x;i<x+len;i++){
        for(int j = y;j<y+len;j++){
            if(BorW[i][j] == 0){
                cnt++;
            }
        }
    }
    if(cnt == len*len){
        return true;
    } 
    return false;
}
int Fold2(int x,int y,int len){
    if(len == 0) {
        return 0;
    }
    if(check2(x,y,len)){
        return 1;
    }
    return Fold2(x,y,len/2) + Fold2(x,y+len/2,len/2)+Fold2(x+len/2,y,len/2) + Fold2(x+len/2,y+len/2,len/2);
}
int main() {
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> BorW[i][j];
        }
    }
    cout << Fold2(0,0,n)  << "\n" << Fold(0,0,n);
}