#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int list[100001];
int number[100001];
int n,m;
int SLV(int number) {
    int start = 0;
    int end = n-1;
    while(true){
    int mid = (start + end )/2;
    if(list[mid] == number) return 1;
    if(start >= end ) return 0;
    if(list[mid] >= number){
        end = mid;
    } else {
        start = mid+1;
    }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> list[i];
    }
    sort(list,list+n);
    cin >> m;
    for(int i = 0;i<m;i++){
        cin >> number[i];
    }
    for(int i = 0;i<m;i++){
       cout << SLV(number[i]) << "\n";
    }
  
}