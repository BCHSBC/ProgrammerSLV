#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n;

int main(){
    int T;
    cin >> T;
    while(T--){
        int a;
        cin >> a;
        vector <int> v;
        int move = 0;
        for(int i = 0;i<20;i++){
            int h;
            cin >> h;
            v.push_back(h);
            int idx = v.size()-1;
            while(idx-1 >=0 && v[idx-1] > v[idx]){
                int tmp = v[idx];
                v[idx] = v[idx-1];
                v[idx-1] = tmp;
                idx--;
                move++;
            }
        }
        cout << a << " " << move << "\n";
    }
}
