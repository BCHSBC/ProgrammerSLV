#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		int c;
		int tm = m;
		int tn = n;
		while (tn != 0) {
			c = tm % tn;
			tm = tn;
			tn = c;
		}
		int lastyear = (m * n) / tm;
		int ans = 0;
		for (int i = x; i <= lastyear; i += m) {
			if (i % n == y  || (i%y == 0 && y == n)) {
				ans = i;
				break;
			}
			
		}
		if (ans == 0) cout << -1 << "\n";
		else cout << ans << "\n";
	}
}