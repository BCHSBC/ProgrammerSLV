#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for(int i = N;i>=1;i--){
        for(int j = 0;j<N-i;j++){
            cout << " ";
        }
        for(int z = 2*i-1;z>=1;z--){
            cout << "*";
        }
        cout << "\n";
    }
}