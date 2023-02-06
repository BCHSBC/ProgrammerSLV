#include <iostream>
#include <string>
#include <queue>
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int list[103][103];
vector <pair<int, int>> v[3];
int n;
int BFS(int opt) {
	int rt= 0;
	bool check[101][101];
	if (opt == 3) {
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				check[i][j] = false;
			}
		}
		for (int i = 0; i < v[2].size(); i++) {
			pair<int, int> p = v[2][i];
			if (check[p.first][p.second]) continue;
			rt++;
			queue<pair<int, int>> q;
			check[p.first][p.second] = true;
			q.push({ p.first,p.second });
			while (!q.empty()) {
				pair<int, int> pp = q.front();
				q.pop();
				for (int i = 0; i < 4; i++) {
					int new_x = pp.first + dx[i];
					int new_y = pp.second + dy[i];

					if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) continue;
					
					if (!check[new_x][new_y] && (list[new_x][new_y] == 1 || list[new_x][new_y] == 2)) {
						check[new_x][new_y] = true;
						q.push({ new_x,new_y });
					}
				}
			}
		}
		for (int i = 0; i < v[1].size(); i++) {
			pair<int, int> p = v[1][i];
			if (check[p.first][p.second]) continue;
			rt++;
			queue<pair<int, int>> q;
			check[p.first][p.second] = true;
			q.push({ p.first,p.second });
			while (!q.empty()) {
				pair<int, int> pp = q.front();
				q.pop();
				for (int i = 0; i < 4; i++) {
					int new_x = pp.first + dx[i];
					int new_y = pp.second + dy[i];

					if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) continue;

					if (!check[new_x][new_y] && (list[new_x][new_y] == 1 || list[new_x][new_y] == 2)) {
						check[new_x][new_y] = true;
						q.push({ new_x,new_y });
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				check[i][j] = false;
			}
		}
		for (int i = 0; i < v[opt].size(); i++) {
			pair<int, int> p = v[opt][i];
			if (check[p.first][p.second]) continue;
			rt++;
			queue<pair<int, int>> q;
			check[p.first][p.second] = true;
			q.push({ p.first,p.second });
			while (!q.empty()) {
				pair<int, int> pp = q.front();
				q.pop();
				for (int i = 0; i < 4; i++) {
					int new_x = pp.first + dx[i];
					int new_y = pp.second + dy[i];

					if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) continue;

					if (!check[new_x][new_y] && (list[new_x][new_y] == opt)) {
						check[new_x][new_y] = true;
						q.push({ new_x,new_y });
					}
				}
			}
		}
	}
	return rt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			char c = str[j];
			if (str[j] == 'R') {
				list[i][j] = 2;
				v[2].push_back({i,j});
			}
			if (str[j] == 'G') {
				list[i][j] = 1;
				v[1].push_back({i,j});
			}
			if (str[j] == 'B') {
				list[i][j] = 0;
				v[0].push_back({i,j});
			}
		}
	}
	int rArea = BFS(2);
	int gArea = BFS(1);
	int bArea = BFS(0);
	int rgArea = BFS(3) + bArea;

	cout << rArea + gArea + bArea << " " << rgArea;
}