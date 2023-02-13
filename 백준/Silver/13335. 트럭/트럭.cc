#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,w,l;
int W[1001];
int main(){
    cin >> n >> w >> l;
    for(int i = 0;i<n;i++){
        cin >> W[i];
    }
    int sum = 0;
    queue <pair<int,int>> q;
    int t = 1;
    int idx;
    sum += W[0];
    q.push({W[0],1});
    int spent = 1;
    idx = 1;
    while(true){
        if(!q.empty()){
            // 현재 시간 계산
            int t = spent - q.front().second;
            if(t >= w){
                sum -= q.front().first;
                q.pop();
            }
        }
        if(idx < n && sum + W[idx] <= l){
            sum += W[idx];
            q.push({W[idx++],spent});               
        }
        if(q.empty()){
            cout << spent;
            break;
        }
        spent++;
    }
}