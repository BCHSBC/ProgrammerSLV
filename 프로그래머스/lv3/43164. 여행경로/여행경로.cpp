#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool visit[20001];
vector<vector<string>> v;
bool cmp(vector<string> a, vector<string> b){
    for(int i = 0;i<a.size();i++){
        if(a[i] != b[i]) return a[i] < b[i];
    }
}
void SLV(string str,vector<vector<string>> tickets,vector<string> path){
    path.push_back(str);
    int count = 0;
    for(int i = 0;i<tickets.size();i++){
        if(!visit[i]){
            count++;
            if(tickets[i][0] == str){
                visit[i] = true;
                SLV(tickets[i][1],tickets,path);
                visit[i] = false;
            }
        }
    }
    if(count == 0){
        v.push_back(path);
    }
    path.pop_back();
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    SLV("ICN",tickets,answer);
    sort(v.begin(),v.end(),cmp);
    answer = v[0];
    return answer;
}