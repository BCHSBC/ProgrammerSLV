#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int l[100001];
int e[100001];
int SLV(int start,int end) {
    int res = 0;
    if(start == end) {
        return 0;
    }
    int smallest = 1000000001;
    int smallestIdx = 0;
    for(int i = start;i<end;i++){    // 가장 싼 주유소에서 ㅈㄴ게 넣으면 됨
        if(smallest > e[i]){
            smallestIdx = i;
            smallest = e[i];
        }
    }
    int sum = 0;
    int liter = 0;
    for(int i = smallestIdx;i<end;i++){
        sum += l[i];
    }
    res = SLV(start, smallestIdx) + e[smallestIdx] * sum;
    return res;
}
int main(){
    cin >> n;
    for(int i = 0;i<n-1;i++){
        cin >> l[i];
    }
    for(int i = 0;i<n;i++){
        cin >> e[i];
    }
    cout << SLV(0,n-1);
}