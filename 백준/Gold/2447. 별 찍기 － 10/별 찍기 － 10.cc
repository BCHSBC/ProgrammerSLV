#include <iostream>
using namespace std;
char list[6563][6563];
void solve(int n,int x,int y){
    if(n<=0){
        list[x][y] = '*';
        return;
    }
    for(int i = x;i<x+n;i++){
        for(int j = y;j<y+n;j++){
            list[i][j] = list[i%n][j%n];
        }
    }
    for(int i =0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(i==1&&j==1) continue;
            else {
                solve(n/3,n/3*i,n/3*j);
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i =0;i<6563;i++){
        for(int j = 0;j<6563;j++){
            list[i][j] = ' ';
        }
    }
    solve(n,0,0);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout << list[i][j];
        }
        cout << "\n";
    }
}