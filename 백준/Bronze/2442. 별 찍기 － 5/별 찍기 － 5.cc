#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for(int i = 1;i<=N;i++){
        for(int j = N-i;j>=1;j--){
            cout << " ";
        }
        for(int z = 1;z<=2*i-1;z++){
            cout << "*";
        }
        cout << "\n";
    }
}