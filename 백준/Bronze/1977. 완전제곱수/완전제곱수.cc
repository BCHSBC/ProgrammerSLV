#include <iostream>
#include <algorithm>
using namespace std;
int* MakeDouble(int list[]) {
    for(int i =1;i<=100;i++){
        list[i] = i*i;
    }
    return list;
}
int main() {
    int list[101] ={};
    int *List = MakeDouble(list);
    int M,N,sum=0,mn=10001;
    cin >> M >> N;
    for(int i =1;i<=100;i++){
        if(List[i] >= M && List[i] <= N){
            mn = min(mn,List[i]);
            sum += List[i];
        }
    }
    if(sum == 0){
        cout << -1;
    }   else {
        cout << sum << "\n" << mn;
    }
    return 0;
}