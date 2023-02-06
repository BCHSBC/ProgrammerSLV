#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, r;
int item[101];
int road[101][101];
int main() {
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		cin >> item[i + 1];
	}
	int s, e, c;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (i == j) {
				road[i][j] = 0;
			}
			else {
				road[i][j] = 999999;
			}
		}
	}
	for (int i = 0; i < r; i++) {
		cin >> s >> e >> c;
		road[s][e] = c;
		road[e][s] = c;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				road[i][j] = min(road[i][j], road[i][k] + road[k][j]);
			}
		}
	}
	int maxItem = 0;

	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (road[i][j] <= m) {
				sum += item[j];
			}
		}
		maxItem = max(maxItem, sum);
	}
	cout << maxItem;
}