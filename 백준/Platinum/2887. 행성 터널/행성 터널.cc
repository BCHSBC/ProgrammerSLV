#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
int n;
vector<vector<int>> dq;
vector <pii> adj[100001];
map <int,int> visited;
bool comp1(vector<int> a, vector<int> b){
    return a[0] < b[0];
}
bool comp2(vector<int> a, vector<int> b){
    return a[1] < b[1];
}
bool comp3(vector<int> a, vector<int> b){
    return a[2] < b[2];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0;i<n;i++){
        int x,y,z;
        cin >> x >> y >> z;
        dq.push_back({x,y,z,i});
    }
    // sort by x-value
    sort(dq.begin(),dq.end(),comp1);
    for(int i = 1;i<dq.size();i++){
        int distance =abs(dq[i][0]-dq[i-1][0]);
        adj[dq[i-1][3]].push_back({distance,dq[i][3]});
        adj[dq[i][3]].push_back({distance,dq[i-1][3]});
    }
    sort(dq.begin(),dq.end(),comp2);
    for(int i = 1;i<dq.size();i++){
        int distance =abs(dq[i][1]-dq[i-1][1]);
        adj[dq[i-1][3]].push_back({distance,dq[i][3]});
        adj[dq[i][3]].push_back({distance,dq[i-1][3]});
    }
    sort(dq.begin(),dq.end(),comp3);
    for(int i = 1;i<dq.size();i++){
        int distance =abs(dq[i][2]-dq[i-1][2]);
        adj[dq[i-1][3]].push_back({distance,dq[i][3]});
        adj[dq[i][3]].push_back({distance,dq[i-1][3]});
    }
    priority_queue<pii> pq;
    for(int i = 0;i<adj[0].size();i++) pq.push({-adj[0][i].first,adj[0][i].second});
    visited[0] = 1;
    int cnt = 0;
    int total = 0;
    while(cnt < n - 1) {
        pii cur = pq.top();
        pq.pop();
        
        int node = cur.second;
        int weight = -cur.first;
        
        if(visited[node] == 1) continue;
        visited[node] = 1;
        cnt++;
        total += weight;
        
        for(int i = 0;i<adj[node].size();i++){
            int next = adj[node][i].second;
            if(visited[next] == 0)pq.push({-adj[node][i].first,next});
        }
        
    }
    cout << total;
}

