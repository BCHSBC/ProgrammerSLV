#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, d;
int DP[10001];
int ss = 0;
vector < pair<pair<int, int>, int>> v;
bool flag = false;
int DFS(int idx) {
	int res = 99999999;
	bool flag = false;
	for (int i = 0; i < ss; i++) {
		int start = v[i].first.first;
		if (start < idx) continue;
		else {
			flag = true;
			res = min(res, DFS(v[i].first.second) + v[i].second + start-idx);
		}
	}
	res = min(res, (d - idx));
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		if (e > d) continue;
		if (e - s < c) continue;
		v.push_back({ {s,e},c });
		ss++;
	}
	int ans = DFS(0);
	cout << ans;
}