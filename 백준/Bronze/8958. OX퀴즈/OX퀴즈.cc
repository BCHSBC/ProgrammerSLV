#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    int N;
    cin >> N;
    while(N--) {
        string ques;
        cin >> ques;
        int *list = new int[ques.size()];
        fill(list,list+ques.size(),0);
        int sum = 0;
        for(int i = 0;i<ques.size();i++) {
            if(ques[i] == 'O') {
                list[i]++;
                if(i != 0) {
                list[i] += list[i-1];
            }
            } else {
                
            }
            sum += list[i];
        }
        cout << sum << "\n";
        delete[] list;
    }
}