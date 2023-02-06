#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int problem,prev =0, sum = 0;
    cin >> problem;
    for(int i = 0;i < problem; i++) {
        int score, tmp;
        cin >> score;
        tmp = score;
        if(score == 0) {
            prev = 0;
        }
        score += prev;
        sum += score;
        prev += tmp;
    }
    cout << sum;
}