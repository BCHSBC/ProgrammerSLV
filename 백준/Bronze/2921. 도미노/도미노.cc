#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int sum = 0;
    for(int i = 0;i<=N;i++){
        for(int j=i;j<=N;j++){
            sum += i+j;
        }
    }
    cout << sum;
}