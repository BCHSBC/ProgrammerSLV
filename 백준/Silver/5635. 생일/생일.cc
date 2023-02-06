#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;
int main() {
    int Person;
    cin >> Person;
    vector<tuple <int,int,int,string>> v;
    while(Person--) {
        string name;
        int date,month,year;
        cin >> name >> date >> month >> year;
        v.push_back(make_tuple(year,month,date,name));
    }
    sort(v.begin(),v.end());
    cout <<get<3>(v[v.size()-1]) << "\n" << get<3>(v[0]);
    return 0;
}