#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int TestCase;
    cin >> TestCase;
    while(TestCase--){
        int c;
        int sumGrade=0;
        float sumGpa=0;
        cin >> c;
        while(c--){
            int grade;
            float gpa;
            cin >> grade >> gpa;
            sumGrade += grade;
            sumGpa += (float)grade*gpa;
        }
        cout << fixed;
        cout.precision(1);
        cout << sumGrade << " " << sumGpa/(float)sumGrade << "\n";
    }
}