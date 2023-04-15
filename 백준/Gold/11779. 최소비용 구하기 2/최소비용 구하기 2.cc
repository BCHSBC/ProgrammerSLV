#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 987654321
int n,m;
int s,e;
int dp[1001];
vector <int> best_path[1001];
vector <pair<int,int>> A[1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // input
    cin >> n;
    cin >> m;
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        A[a].push_back({b,c});

    }
    cin >> s >> e;

    // initialize with MAX value
    for(int i = 0;i<=n;i++){
        dp[i] = MAX;
    }
    priority_queue<pair<int,vector<int>>> pq;
    vector <int> s_input;
    s_input.push_back(s);
    pq.push({0,s_input});
    dp[s] = 0;
    while(!pq.empty()){
        int sum = -pq.top().first;
        vector<int> path = pq.top().second;
        pq.pop();
        if(path[path.size()-1] == e) break;
        int cur_node = path[path.size() -1];
        for(int i = 0;i<A[cur_node].size();i++){
            int new_node = A[cur_node][i].first;
            int len = A[cur_node][i].second;

            if(dp[new_node] > sum + len){
                dp[new_node] = sum + len;
                //best_path[new_node].clear();
                best_path[new_node] = path;
                best_path[new_node].push_back(new_node);
                pq.push({-(sum+len),best_path[new_node]});
            }
        }
    }
    cout << dp[e] << "\n";
    cout << best_path[e].size() <<"\n";
    for(int i = 0;i<best_path[e].size();i++){
        cout << best_path[e][i] << " ";
    }
    
}