#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int N,maxN=-1000001,minN=1000001;
    cin >> N;
    for(int i=0;i<N;i++){
        int number;
        cin >> number;
        maxN = max(maxN,number);
        minN = min(minN,number);
    }
    cout << minN << " " << maxN;
}