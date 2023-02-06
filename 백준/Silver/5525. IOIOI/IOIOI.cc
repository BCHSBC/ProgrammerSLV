#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	int l;
	string str;
	cin >> n >> l >> str;
	string smp = "IOI";
	for (int i = 2; i <= n; i++) {
		smp += "OI";
	}
	int ans = 0;
	while ((str.find(smp) != string::npos)) {
		ans++;
		int idx = str.find(smp);
		str = str.substr(idx+1);
	}
	cout << ans;
}