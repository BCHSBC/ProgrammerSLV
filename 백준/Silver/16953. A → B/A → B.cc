#include <iostream>
#include <algorithm>
using namespace std;

long A, B;
int ans = 9999999;
void SLV(int num, int cnt) {
	if (num < 1) return;
	if (num == A) {
		ans = min(ans, cnt);
		return;
	}
	if (num % 10 == 1) {
		SLV(num / 10, cnt + 1);
	}
	if (num % 2 == 0) {
		SLV(num / 2, cnt + 1);
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> A >> B;
	SLV(B,0);
	if (ans == 9999999) cout << -1;
	else cout << ans+1;
}