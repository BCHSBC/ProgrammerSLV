#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int h[100002];
int main(){
    cin >> N;
    stack <int> s;
    s.push(0);
    for(int i = 1;i<=N;i++){
        cin >> h[i];
    }
    int answer = 0;
    for(int i =1;i<=N+1;i++){
        while(!s.empty() && h[s.top()] > h[i]){
            int tmp = s.top();
            s.pop();
            answer = max(answer,h[tmp] * (i-s.top() -1));
        }
        s.push(i);
    }
    cout << answer;
}