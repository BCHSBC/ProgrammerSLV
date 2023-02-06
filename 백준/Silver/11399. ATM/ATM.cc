#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int n;
vector <int> v;

int main() {
    cin >> n;
    for(int i= 0;i<n;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int sum = 0;
    for(int i = 1;i<v.size();i++){
        v[i] = v[i-1] + v[i];
        sum += v[i];
    }
    sum += v[0];
    cout << sum;
}