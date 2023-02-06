#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector <pair<int,long>> v[5001]; 
int N,Q;
bool check[5001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> Q;
    for(int i = 0;i<N-1;i++){
        int a,b;
        long c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    vector <pair<int,long>> input;
    for(int i = 0;i<Q;i++){
        long a; int b;
        cin >> a >> b;
        input.push_back({b,a});
    }
    for(auto e : input){
        for(int i = 0;i<=N;i++) check[i] = false;
        int res = 0;
        int s = e.first;
        long k = e.second;
        queue <pair<int,long>> q;
        check[s] = true;
        q.push({s,1000000001});
        while(!q.empty()){
            int node = q.front().first;
            long usado = q.front().second;
            q.pop();
            for(int i = 0;i<v[node].size();i++){
                int next = v[node][i].first;
                long value = v[node][i].second;
                if(!check[next]){
                    check[next] = true;
                    long updateUsado = min(usado,value);
                    if(updateUsado >= k) res++;
                    q.push({next,updateUsado});
                }
            }
        }
        cout << res << "\n";
    }
}