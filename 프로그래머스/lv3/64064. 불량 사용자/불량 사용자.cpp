#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
//#include <iostream>
using namespace std;
map <string,vector<string>> m;
map <string,int> IDX;
set <string> s;
bool check[10];
map <string,int> check2;
bool isFit(string a,string b){
    bool flag = false;
    if(a.length() != b.length()) return flag;
    for(int i = 0;i<a.length();i++){
        if(a[i] == b[i] || b[i] == '*'){
            flag = true;
        }else{
            return false;
        }
    }
    return flag;
}
void SLV(int cnt,vector<string>& banned_id,vector<int> v){
    if(cnt == banned_id.size()){
        sort(v.begin(),v.end());
        string str = "";
        for(int i = 0;i<v.size();i++){
            str += to_string(v[i]);
        }
        s.insert(str);
        //cout << str <<"\n";
        return ;
    }
    for(int i = 0;i<m[banned_id[cnt]].size();i++){
        int node = IDX[m[banned_id[cnt]][i]];
        if(!check[node]){
            check[node] = true;
            v.push_back(node);
            SLV(cnt+1,banned_id,v);
            check[node] = false;
            v.pop_back();
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    for(int i = 0;i<user_id.size();i++){
        IDX[user_id[i]] = i;
    }
    for(int i = 0;i<banned_id.size();i++){
        if(check2[banned_id[i]] != 0) continue;
        for(int j = 0;j<user_id.size();j++){
            if(isFit(user_id[j],banned_id[i])){
                check2[banned_id[i]] = 1;
                m[banned_id[i]].push_back(user_id[j]);
            }
        }
    }
    vector<int> v;
    SLV(0,banned_id,v);
    return s.size();
}