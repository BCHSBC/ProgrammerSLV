#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,M;
int L[702][702];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> M >> N;
    for(int i = 0;i<N;i++){
        int c0,c1,c2;
        cin >> c0 >> c1 >> c2;
        int cnt = 0;
        int sx = M,sy = 1;
        while(cnt < 2*M-1){
            int plus = 0;
            if(c0 > 0){
                plus = 0;
                c0--;
            }else if(c1 > 0){
                plus = 1;
                c1--;
            }else if(c2 > 0){
                plus = 2;
                c2--;
            }
            L[sx][sy] += plus;
            if(sx > 1){
                sx--;
            }
            else if(sx == 1){
                sy++;
            }
            cnt++;
        }
    }
    for(int i = 1;i<=M;i++){
        for(int j = 1;j<=M;j++){
            if(i != 1 && j != 1)
                L[i][j] = max(L[i][j],max(L[i-1][j],L[i][j-1]));
            cout << L[i][j] + 1 << " ";
        }
        cout << "\n";
    }
}