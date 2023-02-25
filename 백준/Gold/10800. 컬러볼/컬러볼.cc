#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector <vector<int>> v;
int A[200001];
int B[200001];
int ans[200001];
bool cmp(vector <int> a, vector <int> b){
    if(a[1] == b[1]){
        return a[0] < b[0];
    }
    return a[1] < b[1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int a,b;
    for(int i = 0;i<N;i++){
        cin >> a >> b;
        v.push_back({a,b,i});
    }
    sort(v.begin(),v.end(),cmp);
    int sum = 0;
    for(int i = 0;i<N;i++){
        vector <int> t = v[i];
        A[t[0]] += t[1];
        B[t[1]] += t[1];
        sum += t[1];
        
        ans[t[2]] = sum - A[t[0]] - B[t[1]] + t[1];
        if(i != 0 && v[i-1][0] == t[0] && v[i-1][1] == t[1])
            ans[t[2]] = ans[v[i-1][2]];
    }
    for(int i =0;i<N;i++){
        cout << ans[i] <<"\n";
    }
}