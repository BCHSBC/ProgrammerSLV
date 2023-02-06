#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int L[101][101];
int V[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n;
int main() {
	cin >> n;
	int max_h = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> L[i][j];
			max_h = max(max_h, L[i][j]);
		}
	}
	int max_area = 0;
	for (int h = max_h-1; h >= 0; h--) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				V[i][j] = false;
				if (L[i][j] <= h) V[i][j] = true;
			}
		}
		int area = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!V[i][j]) {
					area++;
					queue <pair<int, int>> q;
					q.push({ i,j });
					V[i][j] = true;
					while (!q.empty()) {
						pair<int, int> p = q.front();
						q.pop();
						for (int d= 0; d < 4; d++) {
							int nx = p.first + dx[d];
							int ny = p.second + dy[d];
							if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
							if (!V[nx][ny]) {
								V[nx][ny] = true;
								q.push({ nx,ny });
							}
						}
					}
				}
			}
		}
		max_area = max(max_area, area);
	}
	cout << max_area;
}