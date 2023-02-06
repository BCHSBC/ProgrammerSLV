#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;
int n, l, r;
int list[51][51];
int tmp[51][51];
bool visited[51][51];
bool start = true;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector <pair<int, int>> v;
bool ispos = false;
bool BFS(int x, int y) {
	queue <pair<int, int>> q;
	visited[x][y] = true;
	q.push({ x,y });
	bool res = false;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int new_x = p.first + dx[i];
			int new_y = p.second + dy[i];
			if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n)continue;
			int gap = abs(list[p.first][p.second] - list[new_x][new_y]);
			if (!visited[new_x][new_y] && gap >= l && gap <= r) {
				visited[new_x][new_y] = true;
				ispos = true;
				q.push({ new_x,new_y });
				res = true;
				v.push_back({ new_x,new_y });
			}
		}
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> list[i][j];
		}
	}
	int cnt = 0;
	while (start) {
		ispos = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = false;
				tmp[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					if (BFS(i, j)) {
						v.push_back({ i,j });
					}
				}
				int sum = 0;
				if (v.size() == 0) continue;

				for (int i = 0; i < v.size(); i++) {
					sum += list[v[i].first][v[i].second];
				}
				int new_pp = sum / v.size();
				for (int i = 0; i < v.size(); i++) {
					tmp[v[i].first][v[i].second] = new_pp;
				}
				v.clear();
			}
		}
		if (!ispos) {
			start = false;
			break;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (tmp[i][j] != 0) {
					list[i][j] = tmp[i][j];
				}
			}
		}
		cnt++;

	}

	cout << cnt;
}