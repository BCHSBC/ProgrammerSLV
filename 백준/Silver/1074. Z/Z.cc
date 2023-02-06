#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int n, r, c;
int dx[4] = { 0,0,1,1 };
int dy[4] = { 0,1,0,1 };
int ans = 0;
int DFS(int len,int x, int y) {
	if (len == 2) {
		for (int i = 0; i < 4; i++) {
			int xx = x +  dx[i];
			int yy = y +  dy[i];
			if (xx == r && yy == c) {
				return i;
			}
		}
	}
	if (len > 2) {
		for (int i = 0; i < 4; i++) {
			int next = len / 2;
			int xx = x + next * dx[i];
			int yy = y + next * dy[i];
			if (xx <= r && r < xx+next && yy <= c && c < yy+next)
			{
				return DFS(next, x + next * dx[i], y + next * dy[i]) + next * next * i;
			}
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> r >> c;
	cout << DFS(pow(2,n), 0, 0);
}