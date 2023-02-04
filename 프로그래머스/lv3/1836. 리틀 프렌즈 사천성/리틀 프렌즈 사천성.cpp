#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
// 먼저 제거 할 수 있는 것들을 확인한다음에 
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

vector <int> findLoc(int x,vector<string> bd){
    vector <int> res;
    char c  = x + 'A';
    for(int i = 0;i<bd.size();i++){
        for(int j = 0;j<bd[i].length();j++){
            if(bd[i][j] == c){
                res.push_back(i);
                res.push_back(j);
                break;
            }
        }
        if(res.size() > 0) break;
    }
    return res;
}
vector<int> isPath(int x,int y,int target,vector<string> bd){
    queue <pair<pair<int,int>,pair<int,int>>> q;
    q.push({{x,y},{-1,-1}});
int dx[4];
int dy[4];
        dx[0] = -1; dx[1] = 1; dx[2] = 0; dx[3] = 0;
    dy[0] = 0; dy[1] = 0; dy[2] = -1; dy[3] = 1;
   while(!q.empty()){
        pair<int,int> p = q.front().first;
        int direc = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();
        if((p.first != x || p.second != y) && bd[p.first][p.second] == (char)(target+'A')){
            int tx = p.first;
            int ty = p.second;
            vector<int> v;
            v.push_back(tx);
            v.push_back(ty);
            
            return v;
        }
        
        for(int i = 0;i<4;i++){
            int plus = 0;
            if(direc != i){
                if(cnt < 1){
                    plus = 1;
                }else{
                    continue;
                }
            }
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(nx <0 || nx >= bd.size() || ny <0 || ny >= bd[0].size()) continue;
            if((bd[nx][ny] == (char)(target+'A') || bd[nx][ny] == '.')){
                q.push({{nx,ny},{i,cnt+plus}});
            }
        }
    }
    vector<int> v;
    v.push_back(-1);
    v.push_back(-1);
    return v;
}
string SLV(vector <int> isE,vector<string> bd){
    string answer="";
    bool check[26];
        for(int i = 0;i<26;i++){
        check[i] = false;
    }
    int cnt = 0;
    while(true){
        bool Find = false;
        for(int x = 0;x<isE.size();x++){
            int i = isE[x];
            if(!check[i]){
                vector <int> loc = findLoc(i,bd);
                vector<int> v = isPath(loc[0],loc[1],i,bd);
                if(v[0] != -1 && v[1] != -1){
                    Find = true;
                    bd[loc[0]][loc[1]] = '.';
                    bd[v[0]][v[1]] = '.';
                    check[i] = true;
                    isE.erase(isE.begin()+x);
                    answer+= (char)(i+'A');
                    break;
                }
            }
        }
        if(Find) continue;
        if(isE.empty()) {
            return answer;
        }else
            break;
 
    }
    return "IMPOSSIBLE";
}
string solution(int m, int n, vector<string> board) {
    vector <string> bd;
    bd = board;
    bool isExist[26];
    for(int i = 0;i<26;i++){
        isExist[i] = false;
    }
    vector<int> isE;
    for(int i = 0;i<board.size();i++){
        for(int j = 0;j<board[i].length();j++){
            if(bd[i][j] >= 'A' && bd[i][j] <= 'Z' && !isExist[bd[i][j]-'A']){
                isExist[bd[i][j]-'A'] = true;
                isE.push_back(bd[i][j]-'A');
            }
        }
    }
    sort(isE.begin(),isE.end());
    return SLV(isE,bd);
}