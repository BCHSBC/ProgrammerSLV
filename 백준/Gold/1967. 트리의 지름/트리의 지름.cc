#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int, int>> v[10001];
bool visit[10001];
int BFS_1(int start) {
	visit[start] = true;
	queue <pair<int, int>> q;
	q.push({ start,0 });
	int max_L = 0;
	int res = 0;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		if (max_L < p.second) {
			max_L = p.second;
			res = p.first;
		}
		for (int i = 0; i < v[p.first].size(); i++) {
			if (!visit[v[p.first][i].first]) {
				visit[v[p.first][i].first] = true;
				q.push({ v[p.first][i].first,p.second + v[p.first][i].second });
			}
		}
	}
	return res;
}
int BFS_2(int start) {
	visit[start] = true;
	queue <pair<int, int>> q;
	q.push({ start,0 });
	int max_L = 0;
	int res = 0;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		if (max_L < p.second) {
			max_L = p.second;
			res = p.first;
		}
		for (int i = 0; i < v[p.first].size(); i++) {
			if (!visit[v[p.first][i].first]) {
				visit[v[p.first][i].first] = true;
				q.push({ v[p.first][i].first,p.second + v[p.first][i].second });
			}
		}
	}
	return max_L;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	int far = BFS_1(1);
	for (int i = 0; i <= n; i++) {
		visit[i] = false;
	}
	int ans = BFS_2(far);
	cout << ans;
}