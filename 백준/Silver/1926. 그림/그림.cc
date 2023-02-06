#include <iostream>
#include <queue>
using namespace std;

int L[501][501];
bool V[501][501];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue <pair<int, int>> q;
int n, m;
int BFS(int i, int j) {
	V[i][j] = true;
	q.push({ i,j });
	int s = 0;
	while (!q.empty()) {
		pair <int, int> p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			if (!V[nx][ny] && L[nx][ny] == 1) {
				V[nx][ny] = true;
				q.push({ nx,ny });
				s++;
			}
		}
	}
	return s + 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> L[i][j];
		}
	}

	int area = 0;
	int max_size = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!V[i][j] && L[i][j] == 1) {
				area++;
				max_size = max(max_size, BFS(i, j));
			}
		}
	}
	cout << area << "\n" << max_size;
}