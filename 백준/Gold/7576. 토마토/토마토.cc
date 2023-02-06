#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

bool visit[1001][1001];
int tomato[1001][1001];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<pair<int, int >> v;
	int zeroCount = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				v.push_back({ i,j });
			}
			if (tomato[i][j] == 0) {
				zeroCount++;
			}
		}
	}
	queue <tuple<int, int, int>> q;
	for (int i = 0; i < v.size(); i++) {
		q.push(make_tuple( v[i].first,v[i].second ,0));
		visit[v[i].first][v[i].second] = true;
	}
	int answer = 0;
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int level = get<2>(q.front());
		answer = level;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int newx = x + dx[i];
			int newy = y + dy[i];

			if (newx < 0 || newx >= m || newy < 0 || newy >= n)
				continue;
			if (newx == 0 && newy == 0) {
				;
			}
			if (tomato[newx][newy] == 0 && !visit[newx][newy]) {
				tomato[newx][newy] = 1;
				q.push(make_tuple(newx, newy, level + 1));
				zeroCount--;
			}
		}
	}
	if (zeroCount) {
		cout << -1;
	}
	else {
		cout << answer;
	}
}