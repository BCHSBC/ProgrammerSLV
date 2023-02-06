#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool check[50][50];
int list[50][50];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n, m,k;
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		vector <pair<int, int>> v;
		queue <pair<int, int>> q;
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				list[i][j] = 0;
				check[i][j] = false;
			}
		}
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back(make_pair(a, b));
			list[a][b] = 1;
		}
		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			if (!check[v[i].first][v[i].second]) {
				q.push(v[i]);
				check[v[i].first][v[i].second] = true;
				while (!q.empty()) {
					int xx = q.front().first;
					int yy = q.front().second;
					q.pop();
					for (int j = 0; j < 4; j++) {
						int newx = xx + dx[j];
						int newy = yy + dy[j];

						if (newx >=  m|| newy >= n || newx < 0 || newy < 0) continue;
						if (!check[newx][newy] && list[newx][newy] == 1) {
							check[newx][newy] = true;
							q.push(make_pair(newx, newy));
						}

					}
				}
				sum++;
			}
			else {
				continue;
			}
		}

		cout << sum << "\n";
	}
}