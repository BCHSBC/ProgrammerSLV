#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int p,m,mm,d,n;
int minAns = 1000000001;
int maxAns = -1000000001;
vector <int> number;
vector <char> cal;
vector <char> cal2;
bool check[11];
int calculate(int a, int b, char c){
    int res = 0;
    switch(c) {
        case '+':
        res = a+b;
        break;
        case '-':
        res = a-b;
        break;
        case '*':
        res = a*b;
        break;
        case '/':
        res = a/b;
        break;
    }
    return res;
}
void SLV(int cnt) {
    if(cnt == p+m+mm+d) {
    int ans = number[0];
    for(int i = 1;i<n;i++){
        ans = calculate(ans,number[i],cal2[i-1]);
    }
    minAns = min(minAns,ans);
    maxAns = max(maxAns,ans);
    return;
    }
    else {
        for(int i = 0;i<p+m+mm+d;i++){
            if(!check[i]){
                check[i] = true;
                cal2.push_back(cal[i]);
                SLV(cnt+1);
                cal2.pop_back();
                check[i] = false;
            }
        }
    }
}
int main() {
    cin >> n;
    for(int i = 0;i<n;i++){
        int num;
        cin >> num;
        number.push_back(num);
    }
    cin >> p >> m >> mm >> d;
    for(int i =0;i<p;i++)cal.push_back('+');
    for(int i =0;i<m;i++)cal.push_back('-');
    for(int i =0;i<mm;i++)cal.push_back('*');
    for(int i =0;i<d;i++)cal.push_back('/');
    SLV(0);
    cout << maxAns << "\n" << minAns;
}