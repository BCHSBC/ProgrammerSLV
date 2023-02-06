#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int x,y,w,h;
    int mingap = 99999;
    cin >> x >> y >> w >> h;
    if(x > w/2){
        if(y> h/2){
            mingap = min(w-x,h-y);
        } else {
            mingap = min(w-x,y);
        }
    } else {
        if(y> h/2){
            mingap = min(x,h-y);
        } else {
            mingap = min(x,y);
        }
    }
    cout << mingap;
}