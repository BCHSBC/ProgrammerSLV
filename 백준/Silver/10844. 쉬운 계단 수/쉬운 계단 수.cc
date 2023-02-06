#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
long cache[101][10];

int main() {
    cin >> n;
    for(int i = 1;i<=9;i++){
        cache[1][i] = 1;
    }
    for(int i = 2;i<=n;i++){
        for(int j=0;j<=9;j++){
            if(j==0){
                cache[i][j] = cache[i-1][j+1];
            } else if(j==9){
                cache[i][j] = cache[i-1][j-1];
            } else{
            cache[i][j] = (cache[i-1][j+1] + cache[i-1][j-1])%1000000000;
            }
            }
    }
    long sum = 0;
    for(int i = 0;i<10;i++){
        sum = (sum+ cache[n][i])%1000000000;
    }
    cout << sum;
}
