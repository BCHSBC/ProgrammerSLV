#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
long value[100001];
long Best[100001];
int main() {
   cin >> n;
   long maxValue = -100000001;
   for(int i = 1;i<=n;i++){
       cin >> value[i];
   }
   for(int i =1;i<=n;i++){
       Best[i] = max(value[i],Best[i-1] + value[i]);
       maxValue = max(maxValue,Best[i]);
   }
   cout << maxValue;
}