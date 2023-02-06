#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for(int i =0;i<N;i++) {
        for(int j=0;j<i;j++){
            cout << " ";
        }
        for(int j=0;j<2*(N-i)-1;j++){
            cout << "*";
        }
        cout << "\n";
    }
    for(int i =N+1;i<2*N;i++){
        for(int j=1;j<(2*N-i);j++){
            cout << " ";
        }
        for(int j=0;j<2*(i-N)+1;j++) {
            cout << "*";
        }
        cout << "\n";
    }
}