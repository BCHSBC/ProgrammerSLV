#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for(int i = 1;i<= N;i++){
        for(int z = N-i;z>0;z--){
            cout << " ";
        }
       for(int j=0;j<i;j++){
           cout << "*";
       }
       cout << "\n";
    }
}