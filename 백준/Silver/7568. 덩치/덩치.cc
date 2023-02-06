#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main(){
    vector <pair<int,int>> v;
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    for(int i = 0;i<v.size();i++){
        int cnt =0;
        int x = v[i].first;
        int y = v[i].second;
        for(int j =0;j<v.size();j++){
            if(i==j)continue;
            int p = v[j].first;
            int q = v[j].second;
            if(p>x && q>y) cnt++;
        }
        cout << cnt+1 << " ";
    }
}