#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int H,W,X,Y;
int L[1001][1001];
int O[1001][1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> H >> W >> X >> Y;
    for(int i = 0;i<H+X;i++){
        for(int j = 0;j<W+Y;j++){
            cin >> L[i][j];
        }
    }
    for(int i = 0;i<H+X;i++){
        for(int j = 0;j<W+Y;j++){
            if(i >= X && j >= Y){
                O[i][j] = L[i][j] - L[i-X][j-Y];
                L[i][j] = O[i][j];
            }else{
                O[i][j] = L[i][j];
            }
        }
    }
    for(int i = 0;i<H;i++){
        for(int j = 0;j<W;j++){
            cout << O[i][j] << " ";
        }
        cout << "\n";
    }
}