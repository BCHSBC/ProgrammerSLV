#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int list[1025][1025];
int sum[1025][1025];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int prev = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> list[i][j];
			if (i == 1) {
				sum[i][j] = list[i][j];
				sum[i][j] += prev;
			}
			else {
				sum[i][j] = sum[i - 1][j] + prev + list[i][j];
			}
			prev += list[i][j];
		}
		prev = 0;
	}
	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << sum[c][d] - sum[c][b - 1] - sum[a - 1][d] + sum[a - 1][b - 1] << "\n";
	}
}