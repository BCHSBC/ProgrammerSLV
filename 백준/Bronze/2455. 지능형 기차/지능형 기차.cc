#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int people = 0;
    int maxPeople = 0;
    for(int i = 0; i < 4;i++) {
        int getOn, getOff;
        cin >> getOff >> getOn;
        people = people - getOff + getOn;
        maxPeople = max(maxPeople,people);
    }
    cout << maxPeople;
}