#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, l, k;
vector <pair<int, int>> v;
bool CHECK(pair<int, int> p, pair<int, int> pp) {
	if (pp.first >= p.first && pp.first <= p.first + l && pp.second >= p.second && pp.second <= p.second + l) return true;

	return false;
}
int main() {
	cin >> n >> m >> l >> k;
	int ans = 0;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });

	}/*
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			pair<int, int> p = { min(v[i].first,v[j].first),min(v[i].second,v[j].second) };
			int cont = 0;
			for (int q = 0; q < k; q++) {
				if (CHECK(p, v[q]))cont++;
			}
			ans = max(ans, cont);
		}
	}
	*/
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			int x = v[i].first;
			int y = v[j].second;
			int cnt = 0;
			for (int q = 0; q < k; q++) {
				int nx = v[q].first;
				int ny = v[q].second;
				if (x <= nx && x + l >= nx && y <= ny && y + l >= ny) cnt++;
			}
			ans = max(ans, cnt);
		}
	}
	cout << k - ans;
}