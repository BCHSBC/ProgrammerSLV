#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int list[9][9];
int co[9][9];
vector <pair<int, int>> zero;
vector <pair<int, int>> sc;
vector <pair<int, int>> virus;
int maxArea = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int getMAX() {
	bool visited[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			visited[i][j] = false;
		}
	}
	queue <pair<int, int>> que;
	copy(&list[0][0], &list[0][0] + 81, &co[0][0]);
	for (int i = 0; i < sc.size(); i++) {
		co[sc[i].first][sc[i].second] = 1;
	}
	for (int i = 0; i < virus.size(); i++) {
		que.push(virus[i]);
	}
	while (!que.empty()) {
		pair <int, int> p = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int new_x = p.first + dx[i];
			int new_y = p.second + dy[i];

			if (new_x <1 || new_x >n || new_y < 1 || new_y >m) continue;
			if (!visited[new_x][new_y] && co[new_x][new_y] == 0) {
				visited[new_x][new_y] = true;
				que.push({ new_x,new_y });
			}
		}

	}

	int count = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (co[i][j] == 0 && !visited[i][j]) count++;
		}
	}

	return count;
}
void SLV(int cnt,int idx) {
	if(cnt == 3) {
		maxArea = max(maxArea, getMAX());
		return;
	}
	else {
		for (int i = idx + 1; i < zero.size(); i++) {
			sc.push_back(zero[i]);
			SLV(cnt + 1, i);
			sc.pop_back();
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> list[i][j];
			if (list[i][j] == 2) virus.push_back({ i,j });
			if (list[i][j] == 0) zero.push_back({ i,j });
		}
	}
	SLV(0,-1);
	cout << maxArea;
}