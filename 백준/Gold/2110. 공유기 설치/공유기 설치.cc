#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
int L[200001];

int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> L[i];
	}
	int ans = 0;
	sort(L, L + n);
	int s = 1, e = L[n - 1]-L[0];
	while (s <= e) {
		int mid = (s + e) / 2;
		int cnt = 1;
		int tmp = L[0];
		for (int i = 1; i < n; i++) {
			int diff = L[i] - tmp;
			if (diff >= mid) {
				cnt++;
				tmp = L[i];
			}
		}
		if (cnt >= c) {
			s = mid + 1;
			ans = mid;
		}
		else {
			e = mid - 1;
		}
	}
	cout << ans;
}