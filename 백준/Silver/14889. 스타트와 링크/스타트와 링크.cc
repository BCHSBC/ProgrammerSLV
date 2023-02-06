#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int list[21][21];
int n;
bool check[21];
int mindiff = 99999999;
void run(){
    vector <int> v;
    vector <int> v1;
    for(int i = 1;i<=n;i++){
        if(check[i]) v.push_back(i);
        else v1.push_back(i);
    }
    int vsum = 0,v1sum = 0;
    for(int i = 0;i<v.size();i++){
        for(int j = i+1;j<v.size();j++){
            vsum += list[v[i]][v[j]] + list[v[j]][v[i]];
        }
    }
    for(int i = 0;i<v1.size();i++){
        for(int j = i+1;j<v1.size();j++){
            v1sum += list[v1[i]][v1[j]] + list[v1[j]][v1[i]];
        }
    }
    int diff = 0;
    if(vsum > v1sum) {
        diff = vsum - v1sum;
    } else {
        diff = v1sum - vsum;
    }
    mindiff = min(mindiff,diff);
}
void slv(int cnt,int idx){
    if(mindiff==0) return;
    
    if(cnt == (n/2)-1){
    
        run();
        return;
    } else {

        for(int i = idx+1;i<=n;i++){
            if(!check[i]){
                check[i] = true;
                slv(cnt+1,i);
                check[i] = false;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    check[1] = true;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> list[i][j];
        }
    }
    slv(0,1);
    cout << mindiff;
}