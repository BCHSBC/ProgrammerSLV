#include <iostream>
#include <string>
using namespace std;
int main() {
    int N;
    cin >> N;
    while(N--) {
        int len;
        string str;
        cin >> len >> str;
        for(int i=0;i<str.length();i++){
            for(int j = 0;j<len;j++){
                cout << str[i];
            }
        }
        cout << "\n";
    }
}
