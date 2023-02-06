#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
using namespace std;

int N;
int C[1001][3];
int bestCost[1001][3];
int minCost = 9999999;
int SLV(int color, int idx){
    if(idx == N){
 
        return 0;
    }
    int &res = bestCost[idx][color];
    if(res != -1) return res;
    res=1000001;
    for(int i = 0;i<3;i++){
        if(abs(color-i)==0) continue;
         res = min(res,SLV(i,idx+1)+C[idx][color]);
       

    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
     for(int i = 0;i<N;i++){
        for(int j=0;j<3;j++){
            bestCost[i][j] = -1;
        }
    }
    for(int i = 0;i<N;i++){
        cin >> C[i][0] >> C[i][1] >> C[i][2];
    }
    cout << min(SLV(0,0),min(SLV(1,0),SLV(2,0)));
   
   
    
}