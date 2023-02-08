#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <tuple>
using namespace std;
int R,C,N;
int M[201][201];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool isGone[201][201];
void SHOOT(){
    for(int i = 1;i<=R;i++){
        for(int j =1;j<=C;j++){
            isGone[i][j] = false;
            M[i][j] += 1;
        }
    }
    for(int i = 1;i<=R;i++){
        for(int j = 1;j<=C;j++){
            if(M[i][j] >= 3){
                M[i][j] = 0;
                isGone[i][j] = true;
                for(int k = 0;k<4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx <= 0 || nx > R || ny <= 0 || ny > C) continue;
                    isGone[nx][ny] = true;
                    
                }
            }
            
        }
    }
    for(int i = 1;i<=R;i++){
        for(int j =1;j<=C;j++){
            if(isGone[i][j]) M[i][j] = 0;
            else M[i][j]++;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C >> N;
    for(int i = 1;i<=R;i++){
        string input;
        cin >> input;
        for(int j=0;j<input.length();j++){
            if(input[j] == '.') M[i][j+1] = 0;
            else {
                M[i][j+1] = 2;
            }
        }
    }
    int t = 0;
    if(N== 1){
        for(int i = 1;i<=R;i++){
        for(int j=1;j<=C;j++){
            if(M[i][j] == 0) cout << '.';
            else cout << 'O';
        }
        cout << "\n";
    }
    }else{
    while(true){
        SHOOT();
        t+=2;
        if(t >= N-1) break;
    }
    if(t > N-1){
        for(int i = 1;i<=R;i++){
        for(int j = 1;j<=C;j++){
            if(M[i][j] == 0){
                cout << 'O';
            }else{
                if(M[i][j] == 1){
                    cout << '.';
                }else{
                    cout << 'O';
                }
            }
        }
        cout << "\n";
        }  
    }else{
    for(int i = 1;i<=R;i++){
        for(int j = 1;j<=C;j++){
            if(M[i][j] == 0){
                cout << '.';
            }else{
                cout << 'O';
            }
        }
        cout << "\n";
        }   
    
    }
    }
}