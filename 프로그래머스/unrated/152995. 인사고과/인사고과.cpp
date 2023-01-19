#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool comp(vector<int>a,vector<int> b){
    return (a[0]+a[1]) > (b[0]+b[1]);
}
int solution(vector<vector<int>> scores) {
    int answer = -1;
    int tx = scores[0][0];
    int ty = scores[0][1];
    sort(scores.begin(),scores.end(),comp);
    int rank = 1;
    int same = 0;
    vector<vector<int>> v;
    int sum = scores[0][1] + scores[0][0];
    for(int i = 0;i<scores.size();i++){
        vector <int> s = scores[i];
        //cout << s[0] << " " << s[1] << "\n";
        bool flag = true;
        for(int j=0;j<v.size();j++){
            if(s[0] < v[j][0] && s[1] < v[j][1]){
                flag = false;
                break;
            }
        }
        if(!flag) continue;
        if(s[0]+s[1] == sum){
            same++;
        }else if(s[0] + s[1] < sum){
            sum = s[0] + s[1];
            rank += same;
            same = 1;
        }
        if(s[0] == tx && s[1] == ty){
            answer = rank;
            break;
        }
        vector <int> t;
        t.push_back(s[0]);
        t.push_back(s[1]);
        v.push_back(t);
    }
    return answer;
}