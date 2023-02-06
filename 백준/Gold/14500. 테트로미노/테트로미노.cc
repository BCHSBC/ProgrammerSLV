#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int list[501][501];
bool visit[501][501];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int maxsum=0;
void DFS(int x, int y,int len,int k) {
	if (len == 4) {
		if (maxsum < k) {
			maxsum = k;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		if (new_x >= n || new_x < 0 || new_y >= m || new_y < 0) continue;
		if (!visit[new_x][new_y]) {
			visit[new_x][new_y] = true;
			DFS(new_x, new_y, len + 1, k + list[new_x][new_y]);
			visit[new_x][new_y] = false;
		}
	}
}
int One(int x, int y) {
	int sum = 0;
	if (x + 1 < n && y + 2 < m) {
		int tmp = 0;
		tmp = list[x][y] + list[x][y + 1] + list[x][y + 2] + list[x + 1][y + 1];
		sum = max(sum, tmp);
	}
	if (x - 1 >= 0 && y + 2 < m) {
		int tmp = 0;
		tmp = list[x][y] + list[x][y + 1] + list[x][y + 2] + list[x -1][y + 1];
		sum = max(sum, tmp);
	}
	if (x + 2 < n && y + 1 < m) {
		int tmp = 0;
		tmp = list[x][y] + list[x + 1][y] + list[x + 2][y] + list[x + 1][y + 1];
		sum = max(sum, tmp);
	}
	if (x + 2 < n && y - 1 >=0) {
		int tmp = 0;
		tmp = list[x][y] + list[x + 1][y] + list[x + 2][y] + list[x + 1][y -1];
		sum = max(sum, tmp);
	}
	return sum;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> list[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = true;
			DFS(i, j,1,list[i][j]);
			visit[i][j] = false;
			maxsum = max(maxsum,One(i, j));
		}
	}
	cout << maxsum;
}