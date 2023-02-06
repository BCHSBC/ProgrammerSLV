#include <iostream>
using namespace std;
int main() {
    int number;
    cin >> number;
    int cnt = 1;
    int renumber = (number%10)*10 + (((number/10)+(number%10))%10);
    while(renumber != number){
        renumber = (renumber%10)*10 + (((renumber/10)+(renumber%10))%10);
        cnt++;
    }
    cout << cnt;
}