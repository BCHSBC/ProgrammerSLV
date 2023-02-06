#include <iostream>
#include <algorithm>

using namespace std;

int n;
int minCost[1000001];
int SLV(){
    minCost[1] = 0;
    for(int i = 2;i<=n;i++){
        minCost[i] = minCost[i-1] + 1;
        if(i%3 == 0){
            minCost[i] = min(minCost[i],minCost[i/3]+1);
        }
        if(i%2 == 0){
            minCost[i] = min(minCost[i],minCost[i/2]+1);
        }
    }
    return minCost[n];
}
int main(){
    cin >> n;
    cout << SLV();
}