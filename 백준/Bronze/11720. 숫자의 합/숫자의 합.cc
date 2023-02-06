#include <iostream>
#include <string>
using namespace std;
int main() {
    int N;
    cin >> N;
    string str;
    cin >> str;
    int sum = 0;
    for(int i = 0;i<str.length();i++){
        int number = str[i] - '0';
        sum += number;
    }
    cout << sum;
}
