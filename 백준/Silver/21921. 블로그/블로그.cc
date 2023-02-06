#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int X, N;
int L[250001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> L[i];
	}
	int s = 0, e = X;
	int sum = 0;
	for (int i = 0; i < e; i++) {
		sum += L[i];
	}
	int max_sum = sum;
	int cnt = 1;
	while (e < N) {
		sum -= L[e - X];
		sum += L[e++];
		if (max_sum == sum) {
			cnt++;
		}
		else if (max_sum < sum) {
			max_sum = sum;
			cnt = 1;
		}

	}
	if (max_sum == 0) {
		cout << "SAD";
	}
	else {
		cout << max_sum << "\n" << cnt;
	}
}
