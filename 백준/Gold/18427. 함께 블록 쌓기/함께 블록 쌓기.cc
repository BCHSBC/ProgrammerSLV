#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int N,M,H;
vector <int> v[52];
int top[1002][52];
int ans = 0;
int SLV(int rest,int idx){
    if(rest < 0) return 0;
    if(rest == 0){
        ans++;
        top[0][idx] = 1;
        return 1;
    }
    if(idx >= N) return 0;
    int res = top[rest][idx];
    if(res != -1) return res;
    res = 0;
    for(int i = 0;i<v[idx].size();i++){
        if(rest - v[idx][i] >= 0){
            res = ( res + SLV(rest-v[idx][i],idx+1) )% 10007;
        }
    }
    top[rest][idx] = res;
    return res;
}
int main(){
    cin >> N >> M >> H;
    cin.ignore();
    for(int i = 0;i<1002;i++){
        for(int j = 0;j<52;j++){
            top[i][j] = -1;
        }
    }
    for(int i = 0;i<N;i++){
        string str;
        getline(cin,str);
        v[i].push_back(0);
        string tmp = "";
        for(int j = 0;j<str.length();j++){
            if(str[j]  == ' '){
                v[i].push_back(stoi(tmp));
                tmp = "";
            }else{
                tmp += str[j];
            }
        }
        v[i].push_back(stoi(tmp));
    }
    
    cout << SLV(H,0);
}