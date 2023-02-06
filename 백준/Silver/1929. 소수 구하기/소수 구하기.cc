#include <iostream>
using namespace std;
int check[1000001];
void filter(int x){
    for(int i = x+x;i<=1000000;i+=x){
        if(!check[i]){
            check[i] = true;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    check[1] = true;
    for(int i = 2;i<=1000000;i++){
        if(!check[i])
            filter(i);
    }
    int m,n;
    cin >> m >> n;
    for(int i = m;i<=n;i++){
        if(!check[i]){
            cout << i << "\n";
        }
    }
}