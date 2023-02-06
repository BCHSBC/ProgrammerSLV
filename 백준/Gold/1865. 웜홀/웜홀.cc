#include <iostream>
#include <queue>
using namespace std;
int n, m, w, t;
int link[501][501];
int hole[501][501];
int cost[501][501];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m >> w;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				link[i][j] = 10001;
				hole[i][j] = 0;
			}
			link[i][i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int s, e,c;
			cin >> s >> e >> c;
			if (link[s][e] != 10001) {
				if (c <= link[s][e]) {
					link[s][e] = c;
					link[e][s] = c;
				}
				else {
					continue;
				}
			}
			link[s][e] = c;
			link[e][s] = c;
		}
		for (int i = 0; i < w; i++) {
			int s, e, c;
			cin >> s >> e >> c;
			link[s][e] = -c;
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					link[i][j] = min(link[i][j], link[i][k] + link[k][j]);
				}
			}
		}
		bool ans = false;
		for (int i = 1; i <= n; i++) {
			if (link[i][i] < 0) {
				ans = true;
				break;
			}
		}
		if (ans) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}