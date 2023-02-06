#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	map <int, int>m;
	vector<pair<int, int>> v;
	vector<pair<int, int>> vv;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		v.push_back({ number,i });
		vv.push_back({ number,i });
	}
	sort(v.begin(), v.end());
	vector <pair<int, int>> b;
	int level = -1;
	for (int i = 0; i < v.size(); i++) {
		if (i >= 1) {
			if (v[i - 1].first == v[i].first) {
				m[v[i].first] = level;
			}
			else {
				m[v[i].first] = ++level;
			}
		}
		else {
			m[v[i].first] = ++level;
		}
	}
	for (int i = 0; i < vv.size(); i++) {
		cout << m[vv[i].first] << " ";
	}
}