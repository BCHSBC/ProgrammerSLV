#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int R,C;
int L[10002][502];
int dx[3] = {-1,0,1};
bool check[10001][501];
int ans = 0;
bool SLV(int x,int y){
    if(y == C-1){
        ans++;
        return true;
    }
    for(int i = 0;i<3;i++){
        int nx = x + dx[i];
        int ny = y + 1;
        if(nx < 0 || nx >= R || ny < 0 || ny>= C) continue;
        if(!check[nx][ny] && L[nx][ny] == '.') {
            check[nx][ny] = true;
            if(SLV(nx,ny)) return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C;
    for(int i = 0;i<R;i++){
        string str;
        cin >> str;
        for(int j = 0;j<str.length();j++){
            L[i][j] = str[j];
        }
    }
    for(int i = 0;i<R;i++){
        check[i][0] = true;
        SLV(i,0);
    }
    cout << ans;
}