#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int L[301][301];
bool V[301][301];
int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int dy[8] = { -2,-1,1,2,-2,-1,1,2 };
queue <pair<pair<int, int>, int>> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int L;
		cin >> L;
		for (int i = 0; i <301; i++) {
			for (int j = 0; j < 301; j++) {
				V[i][j] = false;
			}
		}
		pair<int, int> night;
		pair<int, int> loc;
		cin >> night.first >> night.second;
		cin >> loc.first >> loc.second;
		V[night.first][night.second] = true;
		q.push({ night,0 });
		while (!q.empty()) {
			pair<int, int> p = q.front().first;
			int t = q.front().second;
			q.pop();
			if (p == loc) {
				cout << t<<"\n";
				break;
			}
			for (int i = 0; i < 8; i++) {
				int nx = p.first + dx[i];
				int ny = p.second + dy[i];

				if (nx < 0 || nx >= L || ny < 0 || ny >= L) continue;
				if (!V[nx][ny]) {
					V[nx][ny] = true;
					q.push({ {nx,ny},t + 1 });
				}
			}
		}
		while (!q.empty())q.pop();
	}
}