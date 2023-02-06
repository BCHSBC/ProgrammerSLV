#include <iostream>
#include <algorithm>
using namespace std;

int list[1001][1001];
bool pos[1001][1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			if (i == j) {
				list[i][j] = 0;
				pos[i][j] = true;
			}
			else
			{
				list[i][j] = 999999999;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int s, e, d;
		cin >> s >> e >> d;
		list[s][e] = d;
		pos[s][e] = true;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
					list[j][k] = min(list[j][k], list[j][i] + list[i][k]);
				}
			}
		
	}
	int maxTime = 0;
	for (int i = 1; i <= n; i++) {
		if (x == i) continue;
		maxTime = max(maxTime, list[i][x] + list[x][i]);
	}
	cout << maxTime;
}