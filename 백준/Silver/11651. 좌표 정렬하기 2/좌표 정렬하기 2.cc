#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(pair<int, int> f, pair<int, int> s) {
	if (f.second > s.second) return false;
	else if (f.second == s.second) return f.first < s.first;
	else return true;
}
int main() {
	vector <pair<int, int>> v;
	int n;
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}