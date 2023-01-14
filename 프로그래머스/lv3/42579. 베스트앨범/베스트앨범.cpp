#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>
#include <iostream>
using namespace std;
map <string,int> sum;
map <string,int> cnt;
vector <tuple<string,int,int>> v;
bool comp(tuple<string,int,int> a ,tuple<string,int,int> b){
    if(sum[get<0>(a)] > sum[get<0>(b)]) return true;
    else if(sum[get<0>(a)] == sum[get<0>(b)]){
        if(get<1>(a) > get<1>(b)) return true;
        else if(get<1>(a) == get<1>(b)){
            return get<2>(a) < get<2>(b);
        }
        return false;
    }
    return false;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i = 0;i<plays.size();i++){
        v.push_back(make_tuple(genres[i],plays[i],i));
        sum[genres[i]] += plays[i];
    }
    sort(v.begin(),v.end(),comp);
    for(int i = 0;i<v.size();i++){
        answer.push_back(get<2>(v[i]));
        cnt[get<0>(v[i])]++;
        if(cnt[get<0>(v[i])] > 2) answer.pop_back();
    }
    return answer;
}