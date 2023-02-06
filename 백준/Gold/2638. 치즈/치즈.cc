#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int n, m;
int list[101][101];
int air[101][101];
bool visit[10001];

bool visited[101][101];
vector <pair<int, int>> v;
vector<pair<int, int>> z;
queue <pair<pair<int, int>, int>> q;
void CHANGE(int x, int y) {
	queue <pair<int, int>> qq;
	qq.push({ x,y });
	visited[x][y] = true;
	list[x][y] = 2;
	while (!qq.empty())
	{
		pair<int, int> p = qq.front();
		qq.pop();
		for (int i = 0; i < 4; i++) {
			int new_x = p.first + dx[i];
			int new_y = p.second + dy[i];

			if (new_x <= 0 || new_x > n || new_y <= 0 || new_y > m) continue;
			if (!visited[new_x][new_y] && list[new_x][new_y] == 0) {
				visited[new_x][new_y] = true;
				list[new_x][new_y] = 2;
				qq.push({ new_x,new_y });
			}
		}
	}
}
void SET(int level) {
	for (int i = 0; i < v.size(); i++) {
		if (visit[i])continue;
		int out = 0;
		for (int j = 0; j < 4; j++) {
			int new_x = v[i].first + dx[j];
			int new_y = v[i].second + dy[j];

			if (new_x <= 0 || new_x > n || new_y <= 0 || new_y > m) continue;
			if (list[new_x][new_y] == 2) out++;
		}
		if (out >= 2) {
			q.push({ v[i],level });
			visit[i] = true;
		}
	}
}
void SHOW() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << list[i][j] << " " ;
		}
		cout << "\n";
	}
}
void SLV() {
	int ans = 1;
	SET(1);
	//SHOW();
	while (!q.empty()) {
		pair<int, int> p = q.front().first;
		//cout << p.first << " " << p.second << " " << q.front().second << "\n";
		int time = q.front().second;
		q.pop();
		ans = time;
		CHANGE(p.first, p.second);
		SET(time + 1);
		
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> list[i][j];
			if (list[i][j] == 1) {
				v.push_back({ i,j });
			}
		}
	}
	if (v.size() == 0) {
		cout << 0;
	}
	else {
		CHANGE(1, 1);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				//cout << list[i][j] << " " ;
				if (list[i][j] == 0) {
					z.push_back({ i,j });
				}
			}
			//cout << "\n";
		}
		SLV();
	}
}