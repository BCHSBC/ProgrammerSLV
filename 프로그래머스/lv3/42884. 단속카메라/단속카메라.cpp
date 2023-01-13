#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool check[10001];
int min_cam = 10001;
int ans;
bool comp(vector<int> a , vector<int> b){
    return a[1] < b[1];
}
void SLV(int idx,int cnt,vector<vector<int>>& routes,int level){
    if(cnt == routes.size()){
        ans = cnt;
        return;
    }
    int slv = 0;
    int nextnode=0;
    for(int i = idx;i<routes.size();i++){
        if(check[i]) continue;
        if(routes[idx][1] >= routes[i][0]){
            check[i] = true;
            slv++;
        }else{
            nextnode = i;
            break;
        }
    }
    //cout << nextnode << "\n";
    if(nextnode == 0){
        ans = level;
        return;
    }
    SLV(nextnode,cnt+slv,routes,level+1);
}
int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(),routes.end(),comp);
    SLV(0,0,routes,1);
    return ans;
}