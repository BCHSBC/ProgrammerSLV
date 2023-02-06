#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int testCase;
    cin >> testCase;
    while(testCase--){
        int candy,people;
        cin >> candy >> people;
        cout << "You get " << candy/people << " piece(s) and your dad gets "<< candy % people << " piece(s)." << "\n";
    }
}