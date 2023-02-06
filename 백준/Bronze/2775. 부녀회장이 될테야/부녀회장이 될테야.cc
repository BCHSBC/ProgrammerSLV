#include <iostream>
using namespace std;
int list[15][15];
int main() {
    for(int i = 1;i<15;i++){
        list[0][i] = i;
    }
    for(int i = 1;i<15;i++){
        list[i][1] = 1;
    }
    for(int i = 1;i<15;i++){
        for(int j = 2;j<15;j++){
            list[i][j] = list[i-1][j] + list[i][j-1];
        }
    }
    int T,k,n;
    cin >> T;
    while(T--){
        cin >> k;
        cin >> n;
        cout << list[k][n] << "\n";
    }
}