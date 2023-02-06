#include <iostream>
#include <algorithm>
using namespace std;

int list[501];
int count2[501];
int count5[501];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int number = i;
		int cnt2 = 0;
		int cnt5 = 0;
		while (number % 2 == 0) {
			cnt2++;
			number /= 2;
		}
		while (number % 5 == 0) {
			cnt5++;
			number /= 5;
		}
		count2[i] = count2[i - 1] + cnt2;
		count5[i] = count5[i - 1] + cnt5;
	}
	cout << min(count2[n], count5[n]);
}
