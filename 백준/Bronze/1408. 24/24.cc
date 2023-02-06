#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int sa,sb,sc;
    int ea,eb,ec;
    scanf("%d:%d:%d",&sa,&sb,&sc);
    scanf("%d:%d:%d",&ea,&eb,&ec);
    int sSum=0;
    int eSum=0;
    sSum = 3600*sa+60*sb+sc;
    eSum = 3600*ea+60*eb+ec;
    int time = eSum - sSum;
    if(sSum > eSum) {
        time += 86400;        
    }
    int first = time/3600; time %= 3600;
    int second = time/60; time %= 60;
    int third = time;
    printf("%02d:%02d:%02d",first,second,third);
}