#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
vector<int> first;
vector<int> second;
bool check[10001];
bool comp(vector<int> a, vector<int> b){
    if(a[1] == b[1]) return a[0] < b[0];
    return a[1] > b[1];
}
map<vector<int>,int> index;
void SLV(vector<vector<int>> &nodeinfo,int idx,int leftLimit,int rightLimit){
    first.push_back(index[nodeinfo[idx]]);
    check[index[nodeinfo[idx]]]= true;
    //왼쪽 자식 구하기
    for(int i = idx+1;i<nodeinfo.size();i++){
        if(check[index[nodeinfo[i]]]) continue;
        if(nodeinfo[i][1] < nodeinfo[idx][1] && nodeinfo[i][0] < nodeinfo[idx][0] && nodeinfo[i][0] > leftLimit){
            SLV(nodeinfo,i,leftLimit,nodeinfo[idx][0]);
            break;
        }
    }
    //오른쪽 자식 구하기
    for(int i = idx+1;i<nodeinfo.size();i++){
        if(check[index[nodeinfo[i]]]) continue;
        if(nodeinfo[i][1] < nodeinfo[idx][1] && nodeinfo[i][0] > nodeinfo[idx][0] && nodeinfo[i][0]<rightLimit){
            SLV(nodeinfo,i,nodeinfo[idx][0],rightLimit);
            break;
        }
    }
    second.push_back(index[nodeinfo[idx]]);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    for(int i = 1;i<=nodeinfo.size();i++){
        index[nodeinfo[i-1]] = i;
    }
    sort(nodeinfo.begin(),nodeinfo.end(),comp);
    SLV(nodeinfo,0,-1,100001);
    answer.push_back(first);
    answer.push_back(second);
    return answer;
}