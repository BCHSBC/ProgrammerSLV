#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n;
int cnt = 0;
int sharkSize = 2;
int list[21][21];
bool check[21][21];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
priority_queue<tuple<int, int, int>> q;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> list[i][j];
			if (list[i][j] == 9) {
				q.push({ 0,-i ,- j });
				list[i][j] = 0;
			}
		}
	}
	int ans = 0;
	while (!q.empty()) {
		tuple<int, int, int> t = q.top();
		q.pop();
		int d = -get<0>(t); int x = -get<1>(t); int y = -get<2>(t);

		if (list[x][y] > 0 && list[x][y] < sharkSize) {
			cnt++;
			if (cnt == sharkSize) {
				sharkSize++;
				cnt = 0;
			}
			list[x][y] = 0;
			ans += d;
			d = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					check[i][j] = false;
				}
			}
			while (!q.empty()) q.pop();
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (check[nx][ny]) continue;
			if (list[nx][ny] == 0 || list[nx][ny] <= sharkSize) {
				check[nx][ny] = true;
				q.push({-d-1,-nx,-ny});
			}
		}
	}
	cout << ans;
}