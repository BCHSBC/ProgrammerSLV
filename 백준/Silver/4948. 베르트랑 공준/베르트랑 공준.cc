#include <iostream>
using namespace std;
int check[246913];
void filter(int x){
    for(int i = x+x;i<=246912;i+=x){
        if(!check[i]){
            check[i] = true;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    check[1] = true;
    for(int i = 2;i<=246912;i++){
        if(!check[i])
            filter(i);
    }
    int n;
    while(1){
    cin >> n;
    if(n==0)break;
    int cnt =0;
    for(int i = n+1;i<=2*n;i++){
        if(!check[i]){
            cnt++;
        }
    }
    cout << cnt <<"\n";
    }
}