#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	map <string, int> map1;
	vector <string> v;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		map1[str] = i+1;
	}
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (map1[str]) {
			v.push_back(str);
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}