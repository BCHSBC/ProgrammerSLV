#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector <pair<int, int>> v;
bool cmp(pair<int, int>a, pair<int, int> b) {
	if (a.second > b.second) { return false; }
	else if (a.second == b.second) { return a.first < b.first; }
	else { return true; }
}
int start(int idx) {
	for (int i = idx + 1; i <= n; i++) {
		if (v[i].first >= v[idx].second) {
			return start(i)+1;
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back({ s,e });
	}
	v.push_back({ 0,0 });
	sort(v.begin(), v.end(), cmp);
	cout << start(0);
}