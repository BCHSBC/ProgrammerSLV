#include <map>
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	map<string, string> map;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		map[a] = b;
	}
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		cout << map[str] << "\n";
	}
}