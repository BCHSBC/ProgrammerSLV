#include <iostream>
#include <algorithm>
using namespace std;
int land[501][501];
int minT = 999999999;
int maxH = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, b;
	cin >> n >> m >> b;
	int maxL = 0;
	int minL = 9999;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> land[i][j];
			maxL = max(maxL, land[i][j]);
			minL = min(minL, land[i][j]);
		}
	}
	for (int i = minL; i <=maxL; i++) {
		int sum = 0;
		int time = 0;
		int inv = b;
		bool POS = true;
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				if (i < land[x][y]) { //기준보다 높을 경우
					time += 2 * (land[x][y] - i);
					inv += (land[x][y] - i);

				}
				else {
					continue;
				}
			}
		}
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				if (i > land[x][y]) { //기준보다 낮을 경우
					time += (i - land[x][y]);
					if (inv < (i - land[x][y])) {
						POS = false;
						break;
					}
					else {
						inv -= (i - land[x][y]);
					}
				}
				else {
					continue;
				}
			}
			if (!POS)break;
		}

		if (!POS)continue;
		if (time <= minT && i >= maxH) {
			minT = time;
			maxH = i;
		}
	}
	cout << minT << " " << maxH;
}