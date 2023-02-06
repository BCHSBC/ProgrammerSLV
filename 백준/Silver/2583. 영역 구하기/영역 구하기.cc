#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int m, n, k;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int L[101][101];
bool V[101][101];
int BFS(int i, int j) {
	int res = 1;
	V[i][j] = true;
	queue <pair<int, int>> q;
	q.push({ i,j });
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (!V[nx][ny]) {
				res++;
				V[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = m - y2; i < m - y1; i++) {
			for (int j = x1; j < x2; j++) {
				V[i][j] = true;
			}
		}
	}
	int area = 0;
	vector <int> ans;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!V[i][j]) {
				area++;
				ans.push_back(BFS(i, j));
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}