#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
vector <int> v[300001];
bool check[300001];
long long ans = 0;
long long Search(int node,vector<int>& a){
    long long res = a[node];
    bool flag = false;
    for(int i = 0;i<v[node].size();i++){
        if(!check[v[node][i]]){
            flag = true;
            check[v[node][i]] = true;
            res += Search(v[node][i],a);
        }
    }
    if(!flag){
        ans += (a[node]< 0) ? -a[node] : a[node];
        return a[node];
    }
    ans += (res<0?-res:res);
    return res;
}
long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = -2;
    long long sum = 0;
    int cnt = 0;
    for(int i = 0;i<a.size();i++){
        sum += a[i];
        if(a[i] == 0) cnt++;
    }
    if(sum != 0) return -1;
    if(a.size() == cnt) return 0;
    for(auto e : edges){
        v[e[0]].push_back(e[1]);
        v[e[1]].push_back(e[0]);
    }
    check[0] = true;
    answer = Search(0,a);
    return ans;
}