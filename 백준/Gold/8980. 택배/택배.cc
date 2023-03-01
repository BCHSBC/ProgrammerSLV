 #include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,C,M;
vector <vector<int>> v;
bool cmp(vector<int> a, vector<int> b){
    if(a[1] == b[1]) return a[0] < b[0];
    else return a[1] < b[1];
}
int t[2001];
int main(){
    cin >> N >> C;
    cin >> M;
    for(int i = 0;i<M;i++){
        int s,e,w;
        cin >> s >> e >> w;
        v.push_back({s,e,w});
    }
    sort(v.begin(),v.end(),cmp);
    int start = 1;
    int sum = 0;
    int idx = 0;
    int answer = 0;
    for(int i = 0;i<v.size();i++){
        int s = v[i][0];
        int e = v[i][1];
        int weight = v[i][2];
        int max_t = 0;
        for(int j = s;j<e;j++){
            max_t = max(t[j],max_t);
        }
        int rest = min(weight,C-max_t);
        for(int j = s;j<e;j++){
            t[j] += rest;
        }
        answer += rest;
    }
    cout << answer;
}