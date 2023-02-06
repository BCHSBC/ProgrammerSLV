#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int wine[10001];
int cache[10001][3];
int main(){
    cin >> n;
    int answer = 0;
    for(int i = 1;i<=n;i++){
        cin >> wine[i];
    }
    cache[1][1] = wine[1];
    answer = wine[1];
    for(int i = 2;i<=n;i++){
        cache[i][2] = cache[i-1][1] + wine[i];
        if(i>=2) cache[i][1] = max(cache[i-2][2], cache[i-2][1]) + wine[i];
        if(i>=3) cache[i][1] = max(cache[i][1],max(cache[i-3][2],cache[i-3][1])+wine[i]);
        answer = max(answer,max(cache[i][2],cache[i][1]));
    }
    cout << answer;
    
}
