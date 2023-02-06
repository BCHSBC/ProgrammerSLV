#include <iostream>
#include <algorithm>
using namespace std;
int T, N;
int sticker[2][100001];
int best[2][100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		int bestScore = 0;

		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < N; i++) {
				cin >> sticker[j][i];
			}
		}
		best[0][0] = sticker[0][0];
		best[1][0] = sticker[1][0];
		best[0][1] = best[1][0] + sticker[0][1];
		best[1][1] = best[0][0] + sticker[1][1];
		for (int i = 2; i < N; i++) {
			best[0][i] = max(best[1][i-2], best[1][i - 1] ) +sticker[0][i];
			best[1][i] = max(best[0][i-2], best[0][i - 1] )+sticker[1][i];
			
		}
		cout << max(best[0][N - 1], best[1][N - 1]) << "\n";
	}
}