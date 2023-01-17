#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;
vector <pair<int,int>> v[50001];
bool isSummit[50001];
bool isGate[50001];
int N;
struct comp{
    bool operator()(pii a,pii b){
        if(a.first == b.first) {
            return a.second > b.second;
        }else{
            return a.first < b.first;
        }
    }
};
bool ss(pii a,pii b){
    if(a.first == b.first){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}
vector<int> Search(vector<int> gate){
    vector<int> dist(N+1,10000001);
    priority_queue <pii,vector<pii>,comp> pq;
    for(auto a : gate){
        pq.push({0,a});
        dist[a] = 0;
        //cout << a << "\n";
    }
    vector<pair<int,int>> vec;
    int summit = 0;
    int minIntensity = 10000001;
    
    while(!pq.empty()){
        int intensity = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(isSummit[cur]){
            vec.push_back({intensity,cur});
            continue;
        }
        //cout << pq.top().first << " " << pq.top().second << "\n";
        for(int i = 0;i<v[cur].size();i++){
            int next = v[cur][i].first;
            int newIntensity = max(v[cur][i].second,intensity);
            
            if(!isGate[next]){
                if(newIntensity < dist[next]){
                    dist[next] = newIntensity;
                    pq.push({-newIntensity,next});
                }
            }
            
        }
    }
    
    sort(vec.begin(),vec.end(),ss);
    vector<int> res;
    res.push_back(vec[0].second);
    res.push_back(vec[0].first);
    return res;
}
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {

    vector<int> answer;
    N = n;
    for(auto a : paths){
        v[a[0]].push_back({a[1],a[2]});
        v[a[1]].push_back({a[0],a[2]});
    }
    for(auto a : gates){
        isGate[a] = true;
    }
    for(auto a : summits){
        isSummit[a] = true;
    }
    vector<int> res = Search(gates);

    return res;
}