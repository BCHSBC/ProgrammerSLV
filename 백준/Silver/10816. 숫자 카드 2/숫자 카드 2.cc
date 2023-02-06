#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int list[500001];
int number[500001];
int n,m;
int SLV(int number) {
    int start = 0;
    int end = n;
    while(end > start){
    int mid = (start + end )/2;

    if(list[mid] >= number){
        end = mid;
    } else {
        start = mid+1;
    }
    }
    return end;
}
int SLV2(int number) {
    int start = 0;
    int end = n;
    while(end > start){
    int mid = (start + end )/2;

    if(list[mid] > number){
        end = mid;
    } else {
        start = mid+1;
    }
    }
    return end;
}
int main() {
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> list[i];
    }
    sort(list,list+n);
    cin >> m;
    int maxN = -10000001;
    for(int i = 0;i<m;i++){
        cin >> number[i];
        maxN = max(maxN,number[i]);
    }
    for(int i = 0;i<m;i++){
        
        cout << SLV2(number[i]) -SLV(number[i]) << " ";
    }
  
}