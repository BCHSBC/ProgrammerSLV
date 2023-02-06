#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main() {
    double x1,y1,r1,x2,y2,r2;
    int testCase;
    cin >> testCase;
    while(testCase--){
        cin >> x1>> y1 >> r1 >> x2 >> y2 >> r2;
        double distance = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
        if(r1+r2 < distance){
            cout << 0;
        } else if(r1+r2 == distance){
            cout << 1;
        } else {
            if(r1 > r2){
                int x3,y3,r3;
                x3 = x1; y3=y1;r3=r1;
                x1= x2;y1=y2;r1=r2;
                x2=x3;y2=y3;r2=r3;
            }
            if(distance+r1 <r2){
                cout << 0;
            } else if(distance +r1 == r2){
                if(x1==x2&&y1==y2){
                    cout << -1;
                } else {
                    cout << 1;
                }
            } else{
                cout<<2;
            }
        }
        cout <<"\n";
    }
}