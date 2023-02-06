#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    int TestCase;
    cin >> TestCase;
    while(TestCase--){
        int Person,Max=0;
        string Name;
        cin >> Person;
        while(Person--) {
            int n; string p;
            cin >> n >> p;
            if(Max < n) {
                Name = p;
                Max = n;
            }
        }
        cout << Name << "\n";
    }
}