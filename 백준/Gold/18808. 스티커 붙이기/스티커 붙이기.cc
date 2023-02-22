#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
bool check[41][41];
int N,M,K;
int tmp[10][10];
struct sticker{
    int S[10][10];
    vector <pair<int,int>> sv;
    int R;
    int C;
    int size=0;
};
vector <sticker> v;
void rotate(int idx){
    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            tmp[i][j] = 0;
        }   
    }
    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            tmp[i][j] = v[idx].S[10-j-1][i];
        }
    }
    memmove(v[idx].S,tmp,sizeof(v[idx].S));
    vector <pair<int,int>> tv;
    int minx = 11;
    int miny = 11;
    
    for(int i = 0;i<10;i++){
        for(int j=0;j<10;j++){
            if(v[idx].S[i][j] == 1){
                tv.push_back({i,j});
                minx = min(minx,i);
                miny = min(miny,j);
            }
        }
    }
    for(int i = 0;i<tv.size();i++){
        tv[i].first -= minx;
        tv[i].second -= miny;
    }
    v[idx].sv = tv;
}
pair<int,int> POS(sticker s){
    for(int x = 0;x < N;x++){
        for(int y = 0; y< M;y++){
            bool pos = true;
            for(int i = 0;i<s.sv.size();i++){
                pair<int,int> p = s.sv[i];
                int nx = x + p.first;
                int ny = y + p.second;
                if(nx >= N || ny >= M) {
                    pos = false;
                    break;
                }
                if(check[nx][ny]) {
                    pos = false;
                    break;
                }
            }
            if(!pos) continue;
            return {x,y};
        }
    }
    return {-1,-1};
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >>K;
    for(int i =0;i<K;i++){
        sticker s;
        memset(s.S,0,400);
        int r,c;
        cin >> r >> c;
        s.R = r; s.C = c;
        for(int x = 0;x<r;x++){
            for(int y = 0;y<c;y++){
                cin >> s.S[x][y];
                if(s.S[x][y] == 1){
                    s.size++;
                    s.sv.push_back({x,y});
                }
            }
        }
        v.push_back(s);
    }
    int idx = 0;
    int ans = 0;
            while(idx < K){
                bool flag = false;
                for(int r = 0;r<4;r++){
                    if(r != 0) rotate(idx);
                    pair<int,int> res = POS(v[idx]);
                    if(res.first != -1){
                        for(int i = 0;i<v[idx].sv.size();i++){
                            check[v[idx].sv[i].first+res.first][v[idx].sv[i].second+res.second] = true;
                        }
                        ans += v[idx].size;   
                        flag = true;
                        //cout << idx << " " << res.first << " " << res.second << "\n";
                        break;
                    }
                }
                idx++;
            }
    cout << ans;
}