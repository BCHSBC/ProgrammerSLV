#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
int L[2187][2187];
int n;
int cnt[3];
bool same(int s,int x,int y){
    int e = L[x][y];
    for(int i = x;i < x+s;i++){
        for(int j = y;j < y+s;j++){
            if(L[i][j] != e){
                return false;
            }
        }
    }
    return true;
}
void check(int s,int x,int y){
    
    if(same(s,x,y)){
        cnt[L[x][y]+1] ++;
        return ;
    }
    
    int new_s = s/3;
    if(new_s == 0) return;
    for(int i = 0;i<=new_s*2;i += new_s){
        for(int j = 0;j<=new_s*2;j += new_s){
            check(new_s,x+i,y+j);
        }
    }

}
int main(){
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> L[i][j];
        }
    }
    check(n,0,0);
    for(int i = 0;i<3;i++){
        cout << cnt[i] << "\n";
    }
}
