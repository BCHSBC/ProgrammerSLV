#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;
int h, w;
int L[501][501];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> h >> w;
	vector <int> v;
	for (int i = 0; i < w; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			L[h - j-1][i] = 1;
		}
	}
	int idx = 0;
	int start = -1;
	int sum = 0;
	int se = 0;
	for (int i = 0; i < h; i++) {
		int start = 0;
		int cnt = 0;
		for (int j = 0; j < w; j++) {
			if (L[i][j] == 1 && start == 0) {
				start = 1;
				continue;
			}
			if (L[i][j] == 0 && start != 0) {
				cnt++;
			}
			if (L[i][j] == 1 && start != 0) {
				sum += cnt;
				cnt = 0;
			}
		}
	}
	cout << sum;
}