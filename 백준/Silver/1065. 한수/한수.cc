#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;
bool check[1001];
int sum[1001];
void test(int number){
    string sn = to_string(number);
    bool isit = false;
    for(int i =2;i<sn.length();i++){
        int n1 = sn[i-2] - '0';
        int n2 = sn[i-1] - '0';
        int n3 = sn[i] - '0';
        if(n1 - n2 == n2 - n3) {
            isit = true;
        } else {
            isit = false;
            break;
        }
    }
    check[number] = isit;
}
int main() {
    for(int i = 1;i<=99;i++) {
        check[i] = true;
    }
    for(int i = 100;i<=1000;i++){
        test(i);
    }
    for(int i = 1;i<=1000;i++){
        if(check[i]){
            sum[i]++;
        }
        sum[i] += sum[i-1];
    }
    int N;
    cin >> N;
    cout << sum[N];
}
