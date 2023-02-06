#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n,m;
    vector <int> v;
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    int mingap = 9999999;
    int ans = 0;
    for(int i = 0;i<v.size()-2;i++){
        for(int j = i+1; j < v.size()-1;j++){
            for(int l = j+1;l<v.size();l++){
                int sum = v[i]+v[j]+v[l];
                if(sum > m) continue;
                if(mingap > m-sum){
                    mingap = m-sum;
                    ans = sum;
                }
                
            }
        }
    }
    cout << ans;
}