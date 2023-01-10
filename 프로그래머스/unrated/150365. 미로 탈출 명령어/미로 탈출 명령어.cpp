#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};
char d[4] = {'d','l','r','u'};
bool slv = false;
string answer = "";
void SLV(int n,int m,int x,int y,int r,int c,int k,string ans){
    if(k == 0 && x == r && y == c) {
        slv = true;
        answer = ans;
        return;
    }
     for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
            if(abs(nx-r) + abs(ny-c) > (k-1)) continue;
            SLV(n,m,nx,ny,r,c,k-1,ans+d[i]);
            if(slv) return;
    }
    
}
string solution(int n, int m, int x, int y, int r, int c, int k) {
    
    if(abs(x-r) + abs(y-c) > k) return "impossible";
    if((k-(abs(x-r)+abs(y-c))) % 2 != 0) return "impossible";
    SLV(n,m,x,y,r,c,k,"");
    if(answer == "") answer = "impossible";
    return answer;
}