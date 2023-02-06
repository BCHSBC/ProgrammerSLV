#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int L[17][17];
int n;
int answer = 0;
void SLV(int prevx, int prevy, int curx, int cury,int direct) {
	if (curx == n && cury == n) {
		answer++;
		return;
	}
	if (direct == 0 && cury + 1 <= n && L[curx][cury+1] != 1) {
		SLV(curx, cury, curx, cury + 1, 0);
	}
	if (direct == 0 && cury + 1 <= n && curx +1 <= n&&L[curx+1][cury] != 1 && L[curx][cury+1] != 1 && L[curx + 1][cury + 1] != 1) {
		SLV(curx, cury, curx+1, cury + 1, 2);
	}
	if (direct == 1 && curx + 1 <= n && L[curx+1][cury] != 1) {
		SLV(curx, cury, curx+1, cury, 1);
	}
	if (direct == 1 && curx + 1 <= n && cury+1 <=n && L[curx + 1][cury] != 1 && L[curx][cury + 1] != 1 && L[curx + 1][cury + 1] != 1) {
		SLV(curx, cury, curx + 1, cury+1, 2);
	}
	if (direct == 2 && cury + 1 <= n && L[curx][cury+1] != 1) {
		SLV(curx, cury, curx, cury + 1, 0);
	}
	if (direct == 2 && curx + 1 <= n && L[curx+1][cury] != 1) {
		SLV(curx, cury, curx+1, cury, 1);
	}
	if (direct == 2 && curx + 1 <= n &&cury+1 <=n&& L[curx + 1][cury] != 1 && L[curx][cury + 1] != 1 && L[curx + 1][cury + 1] != 1) {
		SLV(curx, cury, curx + 1, cury+1, 2);
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> L[i][j];
		}
	}
	if (L[n][n] == 1) {
		cout << 0;
	}
	else {
		SLV(1, 2, 1, 2, 0);
		cout << answer;
	}
}