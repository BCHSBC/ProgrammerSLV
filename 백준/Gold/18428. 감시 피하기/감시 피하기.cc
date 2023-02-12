#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
char C[7][7];
bool Tx[7];
bool Ty[7];
bool ans = false;
vector <pair<int,int>> S;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool POS(){
    bool res = true;
    for(int i = 0;i<S.size();i++){
        pair <int,int> p  = S[i];
        for(int x = 0; x< 4;x++){
            int nx = p.first + dx[x];
            int ny = p.second + dy[x];
            while(true){
                if(nx < 0 || nx >= N || ny < 0 || ny>= N){
                    res &= true;
                    break;
                }
                if(C[nx][ny] == 'T'){
                    return false;
                }
                if(C[nx][ny] == 'O'){
                    res &= true;
                    break;
                }
                nx = nx + dx[x];
                ny = ny + dy[x];
            }
        }
    }
    return res;
}
void SLV(int cnt){
    if(cnt == 3){
        if(POS()){
            ans = true;
        }
        return;
    } 
    else{
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                if(C[i][j] == 'T' || C[i][j] == 'S' || C[i][j] == 'O'){
                    continue;
                }
                C[i][j] = 'O';
                SLV(cnt+1);
                C[i][j] = 'X';
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin >> C[i][j];
            if(C[i][j] == 'T'){
                Tx[i] = true;
                Ty[j] = true;
            }
            if(C[i][j] == 'S'){
                S.push_back({i,j});
            }
        }
    }
    bool Promising = true;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(C[i][j] == 'S'){
                for(int x = 0; x<4;x++){
                    int nx = i + dx[x];
                    int ny = j + dy[x];
                    if(nx<0|| nx >= N || ny <0 || ny>=N) continue;
                    if(C[nx][ny] == 'T'){
                        Promising = false;
                        break;
                    }
                }
                if(!Promising) break;
            }
        }
        if(!Promising)break;
    }
    if(!Promising) cout << "NO";
    else{
        SLV(0);
        if(ans) cout << "YES";
        else cout << "NO";
    }
}