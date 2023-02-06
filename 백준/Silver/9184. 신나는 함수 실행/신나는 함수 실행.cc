#include <iostream>
#include <algorithm>
using namespace std;
int wl[101][101][101];
int w(int a, int b, int c){
    int &res = wl[a+50][b+50][c+50];
    if(res != -99999)
        return res;
    bool flag = false;
    if(a <= 0 || b <= 0 || c <= 0){
        res =  1;
        return res;
    }
    if(a > 20 || b > 20 || c > 20){
        res = w(20,20,20);
        return res;
    }
    if(a < b && b < c) {
        res = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
        return res;
    }

 res =  w(a-1,b,c) + w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);

    return res;
}
int main() {
    for(int i = 0;i<101;i++)
        for(int j = 0;j<101;j++)
            for(int z = 0;z<101;z++)
                wl[i][j][z] = -99999;
    while(true){
        int a, b,c;
        cin >>a >> b >> c;
        if(a==-1 && b==-1&&c==-1) break;
        cout << "w(" << a<<", "<< b <<", "<< c << ") = " << w(a,b,c)<<"\n";
    }
}