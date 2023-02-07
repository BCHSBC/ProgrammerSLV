#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define INF 10000000
int N,P,K;
vector <pair<int,int>> v[1002];
int dist[1010];
bool check(int start){
    priority_queue<pair<int,int>> pq;
    pq.push({0,1});
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    while(pq.size()){
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(dist[cur] < cost) continue;
        for(int i = 0;i<v[cur].size();i++){
            int next = v[cur][i].first;
            int ncost = cost + (v[cur][i].second > start);
            if(ncost < dist[next]){
                dist[next ] = ncost;
                pq.push({-ncost,next});
            }
        }
    }
    return dist[N] <= K;
}
int main(){
    cin >> N >> P >> K;
    for(int i = 0;i<P;i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    int ans = -1;
    int s = 0, e = 1e7;
    while(s <= e){
        int mid = (s+e)/ 2;
        if(check(mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid +1;
        }
    }
    cout << ans;
}