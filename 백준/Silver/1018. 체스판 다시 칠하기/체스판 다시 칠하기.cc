#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main(){
    string c[51];
    string p[51];
    int n,m;
    cin >> n >> m;
    for(int i =0;i<8;i++){
        if(i%2==0){
            for(int j=0;j<8;j++){
                if(j%2==0){
                    c[i] += 'W';
                }else{
                    c[i] += 'B';
                }
            }
        }else{
            for(int j=0;j<8;j++){
                if(j%2==0){
                    c[i] += 'B';
                }else{
                    c[i] += 'W';
                }
            }
        }
    }
    int mincnt = 65;
    int cnt = 0;
    for(int i =0;i<n;i++){
        cin >> p[i];
    }
    for(int i =0;i<=n-8;i++){
        for(int j = 0;j<=m-8;j++){
            for(int x = i;x<i+8;x++){
                for(int y = j;y<j+8;y++){
                    if(p[x][y]!=c[x-i][y-j]) cnt++;
                }
            }
            cnt = min(cnt,64-cnt);
            mincnt = min(mincnt,cnt);
            cnt=0;
        }
    }
    cout << mincnt;
}