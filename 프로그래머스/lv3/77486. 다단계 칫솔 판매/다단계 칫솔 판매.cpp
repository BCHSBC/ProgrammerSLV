#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
map <string,string> parent;
map <string,vector<int>> profit;
map <string,int> bbojji;
void giveBBOJJI(string person,int money){
    if(person == "-"){
        return;
    }
    double bj = money * 0.1;
    if(bj < 1){
        bbojji[person] += money;
        return;
    }
    int last = money - (int)bj;
    bbojji[person] += last;
    giveBBOJJI(parent[person],(int)bj);
}
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    for(int i = 0;i<enroll.size();i++){
        string c = enroll[i];
        string p = referral[i];
        parent[c] = p;
    }
    int node = 1;
    for(int i = 0;i<seller.size();i++){
        profit[seller[i]].push_back(amount[i]*100);
    }
    for(int i = 0;i<enroll.size();i++){
        for(int j = 0;j<profit[enroll[i]].size();j++)
            giveBBOJJI(enroll[i],profit[enroll[i]][j]);
    }
    for(int i = 0;i<enroll.size();i++){
        answer.push_back(bbojji[enroll[i]]);
    }
    return answer;
}