#include <iostream>
#include <algorithm>
using namespace std;
int SLV(int a,int b,int c){
    if(b == 0) {
        return 1%c;
    } else if(b==1) {
        return a%c;
    } else {
        long long res = SLV(a,b/2,c);
        if(b %2 ==0) {
            return (res*res) %c;
        } else {
            return ((res*res)%c *a)%c;
        }
    }
}
int main() {
    long long a,b,c;
    cin >> a>> b >> c;
    cout << SLV(a%c,b,c);
}