#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v[18];
int maxS=1;
void DFS(int node,int s,int w,vector<int>& next,vector<int> &info){
    if(info[node] == 0) s++;
    else w++;
    
    maxS = max(maxS,s);
    
    if(w >= s) return;
    
    for(int i = 0;i<next.size();i++){
        vector <int> newnode = next;
        newnode.erase(newnode.begin()+i);
        for(int j = 0;j<v[next[i]].size();j++){
            newnode.push_back(v[next[i]][j]);
        }
        DFS(next[i],s,w,newnode,info);
    }
}
int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    for(int i = 0;i<edges.size();i++){
        int a = edges[i][0];
        int b = edges[i][1];
        v[a].push_back(b);
    }
    vector <int> next;
    for(int i = 0;i<v[0].size();i++)
        next.push_back(v[0][i]);
    
    DFS(0,0,0,next,info);
    return maxS;
}