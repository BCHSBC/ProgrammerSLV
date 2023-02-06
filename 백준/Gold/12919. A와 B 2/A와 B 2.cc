#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s, e;
void CHECK(string str) {
	if (str.length() == 0)return;
	if(str == s){
		cout << 1;
		exit(0);
	}
	if (str[str.length() - 1] == 'A') {
		CHECK(str.substr(0, str.length() - 1));
		if (str[0] == 'B') {
			reverse(str.begin(), str.end());
			CHECK(str.substr(0, str.length() - 1));
		}
	}
	else if (str[0] == 'B') {
		reverse(str.begin(), str.end());
		CHECK(str.substr(0, str.length() - 1));
	}
	
}
int main() {
	cin >> s;
	cin >> e;
	CHECK(e);
	cout << 0;
}
