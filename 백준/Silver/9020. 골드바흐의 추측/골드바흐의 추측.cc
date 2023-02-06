#include <iostream>
#include <algorithm>
using namespace std;
int check[10001];
void filter(int x){
    for(int i = x+x;i<=10000;i+=x){
        if(!check[i]){
            check[i] = true;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    check[1] = true;
    for(int i = 2;i<=10000;i++){
        if(!check[i])
            filter(i);
    }
    int testCase;
    cin >> testCase;
    while(testCase--){
        int number;
        cin >> number;
        int n1,n2,gap=99999;
        for(int i = 2;i<=number/2;i++){
            if(!check[i]){
                if(!check[number-i]){
                    if(number-2*i < gap){
                        gap = number - 2*i;
                        n1 = i;
                        n2 = number-i;
                    }
                }
            }
        }
        cout << n1 << " " << n2 << "\n";
    }
}