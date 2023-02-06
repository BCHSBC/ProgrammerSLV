#include <iostream>
#include <algorithm>
using namespace std;
long long int list[101];
long long int slv(int idx){
    long long int &res = list[idx];
    if(res!= -1) return res;
    res = slv(idx-1) + slv(idx-5);
    return res;
}
int main() {
    for(int i =1;i<=100;i++){
        list[i] = -1;
    }
    list[1] = 1; list[2] = 1;
    list[3] = 1; list[4] = 2;
    list[5] = 2;
    for(int i = 6;i<=100;i++){
        list[i] = slv(i);
    }
    int T;
    cin >> T;
    while(T--){
    int n;
    cin >> n;
    cout << list[n] << "\n";
    }
}