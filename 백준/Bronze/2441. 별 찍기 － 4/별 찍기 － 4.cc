#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for(int i = 1;i<= N;i++){
        for(int z = 1;z<i;z++){
            cout << " ";
        }
       for(int j=N-i+1;j>0;j--){
           cout << "*";
       }
       cout << "\n";
    }
}
