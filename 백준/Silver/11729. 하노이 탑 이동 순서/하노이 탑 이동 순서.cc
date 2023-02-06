/*
첫번째 장대에서 세번째 장대로 옮긴다.
한번에 한개의 원판만 옮긴다.
쌓아놓은 원판은 항상 위의 것이 아래의 것보다 작아야한다.
P(N) = 2*P(N-1) +1 
2*P(N-1) -> 
1.P(N-1)짜리를 기준축과 마지막 원판을 놓을 축을 제외한 나머지 축에 둔다 ,
2.마지막 원판을 옮길 축에 둔다. 
3.나머지 축에 있는 P(N-1)를 마지막 원판이 있는 축에 둔다.
*/
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
void solve(int num,int a, int b){
    if(num <= 1){
        cout << a << " " << b <<"\n";
    } else {
        int c = 6-a-b;
        solve(num-1,a,c);
        cout << a << " " <<  b << "\n";
        solve(num-1,c,b);
    }
}
int main(){
    int num;
    cin >> num;
    cout << int(pow(2,num))-1 << "\n";
    solve(num,1,3);
    
}