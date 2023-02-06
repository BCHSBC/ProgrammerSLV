#include <iostream>
#include <algorithm>
using namespace std;
#define MAXINT 987654321;
int n, e, a, b, c,x,y;
int list[801][810];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> e;
	for (int i = 0; i < 801; i++) {
		for (int j = 0; j < 801; j++) {
			if (i == j) list[i][j] = 0;
			else
			list[i][j] = MAXINT;
		}
	}
	for (int i = 0; i < e; i++) {
		int start, end, distance;
		cin >> start >> end >> distance;
		list[start][end] = distance;
		list[end][start] = distance;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				list[i][j] = min(list[i][j], list[i][k]+list[k][j]);
			}
		}
	}
	cin >> x >> y;
	int ans = 987654321;
	if (list[1][x] == 987654321 || list[x][y] == 987654321 || list[y][n] == 987654321) {
		;
	}
	else {
		ans = min(ans, list[1][x] + list[x][y] + list[y][n]);
	}
	if (list[1][y] == 987654321 || list[y][x] == 987654321 || list[x][n] == 987654321) {
		;
	}
	else {
		ans = min(ans, list[1][y] + list[y][x] + list[x][n]);
	}

	if (ans == 987654321)cout << -1;
	else {
		cout << ans;
	}
}