#include <iostream>
#include <algorithm>

using namespace std;

int list[224];
int dp[50001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int k = 0;
	for (int i = 0; i <= 50000; i++) {
		dp[i] = 10;
	}
	dp[0] = 0;
	for (int i = 1; i <= 223; i++) {
		list[i] = i * i;
		if (list[i] <= n) {
			k = i;
		}
		dp[list[i]] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i >= list[j]) {
				if ((dp[i - list[j]] + dp[list[j]]) <= 4) {
					dp[i] = min(dp[i], dp[i - list[j]] + dp[list[j]]);
				}
			}
		}
	}
	cout << dp[n];
}