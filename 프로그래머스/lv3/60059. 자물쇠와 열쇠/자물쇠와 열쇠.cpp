#include <string>
#include <vector>
#include <algorithm>
//#include <iostream>
using namespace std;
int hole=0;
int L[61][61];
int Lsize;
vector<vector<int>> rotate(vector<vector<int>> v){
    vector<vector<int>> res = v; //초기화용
    for(int i = 0;i<v.size();i++){
        for(int j = 0;j<v.size();j++){
            res[i][j] = v[v.size()-j-1][i];
        }
    }
    return res;
}
bool CHECK(vector<vector<int>> key,int ox,int oy){
    int tmp[61][61];
    for(int i = 20;i<20+Lsize;i++){
        for(int j = 20;j<20+Lsize;j++){
            tmp[i][j] = 0;
        }
    }
    int ks = key.size();
    for(int i = 0;i<key.size();i++){
        for(int j = 0;j<key.size();j++){
            tmp[i+ox-ks][j+oy-ks] = key[i][j];
        }
    }
    int hcount = 0;
    for(int i = 20;i<ox && i< 20 + Lsize;i++){
        for(int j = 20;j< oy && j < 20 + Lsize;j++){
            if(L[i][j] == 0 && tmp[i][j] == 1) hcount++;
            if(L[i][j] == 1 && tmp[i][j] == 1) return false;
            if(hcount == hole){
                return true;
            }
        }
    }
    return false;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    Lsize = lock.size();
    for(int i = 0;i<lock.size();i++){
        for(int j = 0;j<lock.size();j++){
            L[i+20][j+20] = lock[i][j];
            if(lock[i][j] == 0) hole++;
        }
    }
    int len = 20 + lock.size() + key.size() - 1;
    for(int i = 20;i<=len;i++){
        for(int j = 20;j<=len;j++){
            vector<vector<int>> tmp = key;
            for(int k = 0;k<4;k++){
                tmp = rotate(tmp);
                if(CHECK(tmp,i,j)){
                    //cout << i << " " << j;
                    return true;
                }
            }
        }
    }
    return answer;
}