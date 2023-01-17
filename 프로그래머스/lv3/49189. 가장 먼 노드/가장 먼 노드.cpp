#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool check[20001];
vector <int> v[20001];
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(auto e : edge){
        v[e[0]].push_back(e[1]);
        v[e[1]].push_back(e[0]);
    }
    vector <int> ans;
    check[1] = true;
    queue <pair<int,int>> q;
    q.push({1,0});
    int maxlen = 1;
    while(!q.empty()){
        int node = q.front().first;
        int level = q.front().second;
        if(level > maxlen){
            maxlen = level;
            ans.clear();
            ans.push_back(node);
        }else if(level == maxlen){
            ans.push_back(node);
        }
        q.pop();
        for(int i = 0;i<v[node].size();i++){
            int next = v[node][i];
            if(!check[next]){
                check[next] = true;
                q.push({next,level+1});
            }
        }
    }
    return answer=ans.size();
}