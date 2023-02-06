#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int L[126][126];
int dp[126][126];
bool visited[126][126];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cnt = 1;
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> L[i][j];
				visited[i][j] = false;
				dp[i][j] = 99999999;
			}
		}
		queue <pair<pair<int, int>,int>> q;
		q.push({ {0,0} ,L[0][0] });
		visited[0][0] = true;
		dp[0][0] = L[0][0];
		int ans = 0;
		while (!q.empty()) {
			pair<int, int> p = q.front().first;
			int sum = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int new_x = p.first + dx[i];
				int new_y = p.second + dy[i];
				if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n)continue;
				if (dp[new_x][new_y] > dp[p.first][p.second] + L[new_x][new_y]) {
					dp[new_x][new_y] = dp[p.first][p.second] + L[new_x][new_y];
					q.push({ {new_x,new_y},dp[new_x][new_y] });
				}
			}
		}
		cout << "Problem " << cnt << ": " << dp[n-1][n-1] << "\n";
		cnt++;
	}
}