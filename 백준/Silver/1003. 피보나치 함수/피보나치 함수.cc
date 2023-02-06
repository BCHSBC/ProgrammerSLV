#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int howMany[41][2];
int slv(int idx,int flag){
    int res = howMany[idx][flag];
    if(res != -1){
        return res;
    }
    res = slv(idx-1,flag) + slv(idx-2,flag);
    return res;
}
int main(){
    for(int i = 0;i<=40;i++){
        for(int j = 0;j<=1;j++){
            howMany[i][j] = -1;
        }
    }
    howMany[0][0] = 1; howMany[0][1] = 0;
    howMany[1][1] = 1; howMany[1][0] = 0;
    for(int i = 2;i<=40;i++){
        howMany[i][0] = slv(i,0);
        howMany[i][1] = slv(i,1);
    }    
    
    int testCase;
    cin >> testCase;
    for(int i = 0;i<testCase;i++){
        int number;
        cin >> number;
        cout << howMany[number][0] << " " << howMany[number][1] << "\n";
    }
}