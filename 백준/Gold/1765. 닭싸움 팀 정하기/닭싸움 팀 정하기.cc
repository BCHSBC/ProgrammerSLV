#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n,m;
vector <int> F[1001];
vector <int> E[1001];
int parent[1001];
bool check[1001];
map <int, vector<int>> team;
int ans = 0;
int getP(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = getP(parent[x]);
}
void Check(int x){
    check[x] = true;
    if(parent[x] == x){
        return;
    }
    return Check(parent[x]);
}
void Union(int a,int b){
    a = getP(a);
    b = getP(b);
    if(a<b){
        parent[b] = a;
    }else{
        parent[a] = b;
    }
}
int main(){
    cin >> n;
    cin >> m;
    for(int i = 1;i<=n;i++){
        parent[i] = i;
    }
    for(int i = 0;i<m;i++){
        char c;
        int a,b;
        cin >> c >> a >> b;
        if(c == 'F'){
            Union(a,b);
        }else{
            E[a].push_back(b);
            E[b].push_back(a);
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<E[i].size();j++){
            for(int x = 0;x<E[E[i][j]].size();x++){
                Union(i,E[E[i][j]][x]);
            }
        }
    }
    for(int i = 1;i<=n;i++){
        if(parent[i] == i){
            ans++;
        }
    }
    cout << ans;
}