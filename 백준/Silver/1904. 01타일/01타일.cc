#include <iostream>
#include <algorithm>
using namespace std;
int list[1000001];
int slv(int idx){
    int &res = list[idx];
    if(res!= -1) return res;
    res = (list[idx-1] + list[idx-2])%15746;
    return res;
}
int main() {
    for(int i =1;i<=1000000;i++){
        list[i] = -1;
    }
    list[1] = 1; list[2] = 2;
    for(int i = 3;i<=1000000;i++){
        list[i] = slv(i);
    }
    int n;
    cin >> n;
    cout << list[n];
}