#include <iostream>
using namespace std;
int list[21];
int fibo(int x){
    if(x== 0) return 0;
    else if(x==1) return 1;
    else {
       return fibo(x-1) + fibo(x-2);
    }
}
int main(){
    int n;
    cin >> n;
    for(int i =0;i<=n;i++){
       list[i] =  fibo(i);
    }
    cout << list[n];
}