#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int testCase;
    cin >> testCase;
    for(int i = 1;i<=testCase;i++){
      int n1,n2;
      cin >> n1 >> n2;
      cout << "Case " << i << ": " << n1+n2 << "\n";
    }
}