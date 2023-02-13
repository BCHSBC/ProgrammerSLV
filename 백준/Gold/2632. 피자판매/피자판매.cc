#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int N;
int m,n;

int L[1000];
int R[1000];
map <int,int> lt;
map <int,int> rt;
map <int,int> lexist;
vector <int> ll;
int main(){
    cin >> N;
    cin >> m >> n;
    int lsum=0,rsum=0;
    for(int i = 0;i<m;i++){
        cin >> L[i];
        lsum += L[i];
    }
    for(int i = 0;i<n;i++){
        cin >> R[i];
        rsum += R[i];
    }
    lt[0] = 1;
    lt[lsum] = 1;
    ll.push_back(0);
    ll.push_back(lsum);
    rt[0] = 1;
    rt[rsum] = 1;
    for(int i = 0;i<m;i++){
        int sum = 0;
        for(int j = 0;j<m-1;j++){
            int side = i+j;
            if(side >= m) side -=m;
            sum += L[side];
            lt[sum]++;
            if(lexist[sum] != 0) continue;
            lexist[sum] = 1;
            ll.push_back(sum);
        }
    }
    for(int i = 0;i<n;i++){
        int sum = 0;
        for(int j = 0;j<n-1;j++){
            int side = i+j;
            if(side >= n) side -=n;
            sum += R[side];
            rt[sum]++;
        }
    }
    int ans = 0;
    for(int i = 0;i<ll.size();i++){
        int leftover = N - ll[i];
        if(rt[leftover] != 0){
            ans += (lt[ll[i]] * rt[leftover]);
        }
    }
    cout << ans;
}