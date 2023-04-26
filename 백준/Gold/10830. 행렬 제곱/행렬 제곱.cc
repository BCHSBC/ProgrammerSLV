#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<vector<ll>> list;
vector<vector<ll>> ans;
vector<vector<ll>> tmp;
ll n,times;

vector<vector<ll>> operator * (const vector<vector<ll>>& a,const vector<vector<ll>>& b){
    int size = a.size();
    vector<vector<ll>> res(size,vector<ll>(size));
    
    for(int i = 0;i<size;i++){
        for(int j=0;j<size;j++){
            for(int k=0;k<size;k++){
                res[i][j] += a[i][k] * b[k][j];
            }
            res[i][j] %= 1000;
        }
    }
    return res;
}

vector<vector<ll>> power(vector<vector<ll>> a,ll b){
    int size = a.size();
    vector<vector<ll>> res(size,vector<ll>(size));
    for(int i = 0;i<size;i++){
        res[i][i] = 1;
    }
    
    while(b>0){
        if(b%2 == 1){
            b -= 1;
            res = res*a;
        }else{
            a = a * a;
            b /= 2;
        }
    }
    return res;
}
int main(){
    cin >> n >> times;
    for(int i = 0;i<n;i++){
        vector<ll> tmpt;
        for(int j = 0;j<n;j++){
            ll number;
            cin >> number;
            tmpt.push_back(number);
        }
        list.push_back(tmpt);
    }
    vector<vector<ll>> ans = power(list,times);
    for(int i = 0;i<ans.size();i++){
        for(int j = 0;j<ans.size();j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}
