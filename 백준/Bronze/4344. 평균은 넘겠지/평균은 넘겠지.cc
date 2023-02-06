#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    int N;
    cin >> N;
    while(N--) {
        int student;
        int sum=0;
        cin >> student;
        int list[1001];
        for(int i = 0;i<student;i++){
            int score;
            cin >> score;
            list[i] = score;
            sum += score;
        }
        double avr = (double)sum / (double)student;
        double cnt = 0;
        for(int i = 0;i<student;i++) {
            if((double)list[i]>avr) {
                cnt++;
            }
        }
        double ans = cnt /(double)student;
        cout << fixed;
        cout.precision(3);
        cout << ans *100 << "%" << "\n";
    }
}