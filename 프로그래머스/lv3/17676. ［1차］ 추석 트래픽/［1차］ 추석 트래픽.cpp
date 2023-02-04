#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int solution(vector<string> lines) {
    int answer = 0;
    long startT;
    vector <pair<double,double>> v;
    for(int i = 0;i<lines.size();i++){
        double hour = stoi(lines[i].substr(11,2))*60*60;
        double minute = stoi(lines[i].substr(14,2))*60;
        double second = stoi(lines[i].substr(17,2));
        double msecond = stoi(lines[i].substr(20,3))/1000.0;
        double end = hour+ minute + second + msecond;
        string s = lines[i].substr(24);
        double period = stod(s.substr(0,s.length()-1));
        double start = end - period+ 0.001;
        if(start < 0){
            start = 0;
        }
        v.push_back({start,end});
    }
    int ans = 0;
    for(int i = 0;i<v.size();i++){
        double start = v[i].first;
        double end = v[i].second;
        ans = 1;
        for(int j = i+1;j<v.size();j++){
            if(v[j].first <= start + 1 || v[j].first < end+1){
                ans++;
            }
        }
        answer = max(answer,ans);
    }
    return answer;
}