#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	map <string, int> si;
	map <int, string> is;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		si.insert({ str,i });
		is.insert({ i,str });
	}
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (str[str.length() - 1] <= '9' && str[str.length() - 1] >= '0') {
			int number = stoi(str);
			cout << is[number] << "\n";
		}
		else {
			cout << si[str] << "\n";
		}
	}
}