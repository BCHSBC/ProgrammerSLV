#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool check;
typedef struct K{
    int from;
    int to;
    int val;
};
vector <K> edge;
int parent[101];
int res;
bool comp(K a,K b){
    return a.val < b.val;
}
int find(int c){
    if( c == parent[c]) return c;
    return parent[c] = find(parent[c]);
}
void merge(int u,int v){
    check = false;
    u = find(u);
    v = find(v);
    
    if(u == v) return;
    parent[u] = v;
    check = true;
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i = 0;i<n;i++){
        parent[i] = i;
    }
    for(int i = 0;i<costs.size();i++){
        K k;
        k.from = costs[i][0];
        k.to = costs[i][1];
        k.val = costs[i][2];
        edge.push_back(k);
    }
    sort(edge.begin(),edge.end(),comp);
    for(int i = 0;i<edge.size();i++){
        merge(edge[i].from,edge[i].to);
        if(check)
            answer+= edge[i].val;
    }
    return answer;
}