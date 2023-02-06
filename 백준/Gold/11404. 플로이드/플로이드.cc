#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cost[101][101];
int dist[101][101];
int n, m;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cin >> m;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (i == j) continue;
			cost[i][j] = 99999999;
		}
	}
	for (int i = 0; i < m; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		if (cost[s][e] == 99999999 || cost[s][e] > c) {
			cost[s][e] = c;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cost[i][j] = min(cost[i][j],cost[i][k] + cost[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cost[i][j] == 99999999) cout << 0 << " ";
			else cout << cost[i][j] << " ";
		}
		cout << "\n";
	}
}