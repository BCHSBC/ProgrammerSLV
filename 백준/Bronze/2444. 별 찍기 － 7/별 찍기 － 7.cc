#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for(int i = 1;i<=N;i++){
        for(int j = N-i;j > 0;j--){
            cout << " ";
        }
        for(int z = 1;z<=2*i-1;z++){
            cout << "*";
        }
        cout << "\n";
    }
    for(int i = N+1;i<=2*N-1;i++){
        for(int j = N+1;j<=i;j++){
            cout << " ";
        }
        for(int z = 2*(2*N-i)-1;z>=1;z--){
            cout << "*";
        }
        cout << "\n";
    }
}