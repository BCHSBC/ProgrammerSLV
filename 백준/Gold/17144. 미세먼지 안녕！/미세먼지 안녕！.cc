#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int r, c, t;
int L[51][51];
int tmp[51][51];
int tmp2[51][51];
vector <pair<int, int>> vv;
int fx, fy, sx, sy;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void SET() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			tmp[i][j] = 0;
		}
	}
}
void SPREAD() {
	SET();
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (L[i][j] < 5) continue;
			int cnt = 0;
			for (int d = 0; d < 4; d++) {
				int new_x = i + dx[d];
				int new_y = j + dy[d];

				if (new_x <= 0 || new_x > r || new_y <= 0 || new_y > c) continue;
				if (L[new_x][new_y] == -1) continue;
				tmp[new_x][new_y] += floor(L[i][j] / 5);
				cnt++;
			}
			L[i][j] -= floor(L[i][j] / 5) * cnt;
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			L[i][j] += tmp[i][j];
		}
	}
	
}
void TOP(int x, int y, int direct) {
	int new_x = x + dx[direct];
	int new_y = y + dy[direct];
	if (new_x == fx && new_y == fy) {
		L[x][y] = 0;
		return;
	}
	tmp[new_x][new_y] = L[x][y];
	L[x][y] = 0;
	if (new_x == 1 && new_y == 1) {
		TOP(new_x, new_y, 1);
		return;
	}
	if (new_x == 1 && new_y == c) {
		TOP(new_x, new_y, 2);
		return;
	}
	if (new_x == fx && new_y == c) {
		TOP(new_x, new_y, 0);
		return;
	}
	TOP(new_x, new_y, direct);
}
void BOTTOM(int x, int y, int direct) {
	int new_x = x + dx[direct];
	int new_y = y + dy[direct];
	if (new_x == sx && new_y == sy) {
		L[x][y] = 0;
		return;
	}
	tmp[new_x][new_y] = L[x][y];
	L[x][y] = 0;
	if (new_x == r && new_y == c) {
		BOTTOM(new_x, new_y, 2);
		return;
	}
	if (new_x == r && new_y == 1) {
		BOTTOM(new_x, new_y, 0);
		return;
	}
	if (new_x == sx && new_y == c) {
		BOTTOM(new_x, new_y, 1);
		return;
	}
	BOTTOM(new_x, new_y, direct);
}
void SAVE() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (tmp[i][j] != 0) {
				L[i][j] = tmp[i][j];
			}
		}
	}
}
int main() {
	cin >> r >> c >> t;
	int size = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> L[i][j];
			if (L[i][j] == -1) {
				if (size == 0) {
					fx = i; fy = j;
					size++;
				}else {
					sx = i; sy = j;
				}
			}
		}
	}
	while (t--) {
		SPREAD();
		SET();
		TOP(fx, fy + 1, 3);  
		BOTTOM(sx, sy + 1, 3); 
		SAVE();
	}
	int answer = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (L[i][j] != -1)
				answer += L[i][j];
		}
	}

	cout << answer;
}