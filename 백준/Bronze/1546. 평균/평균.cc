#include <iostream>
#include <algorithm>
using namespace std;
float score[1001];
int main() {
    ios::sync_with_stdio(false);
    int test;
    cin >> test;
    float maxScore = 0;
    for(int i = 0;i < test;i++) {
        cin >> score[i];
        maxScore = max(maxScore,score[i]);
    }
    float sum = 0;
    for(int i = 0;i < test;i++) {
        sum += (score[i]/maxScore) * 100;
    }
    cout << sum/(float)test;
}