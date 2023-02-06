#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int school;
    cin >> school;
    int lastApple=0;
    while(school--){
        int student,apple;
        cin >> student >> apple;
        lastApple += apple % student;
    }
    cout << lastApple;
}