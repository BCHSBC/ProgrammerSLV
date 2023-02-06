#include <iostream>
#include <math.h>
using namespace std;
int ans;
int n;
int check[16];
bool pos(int h) {
	for (int i = 0; i < h; i++) {
		if (check[i] == check[h] || check[h] - check[i] == h - i || check[i] - check[h] == h - i)
		{
			return false;
		}
	}
	return true;
}
void Queen(int floor) {
	if (n == floor) {
		ans++;
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			check[floor] = i;
			if (pos(floor)) {
				Queen(floor + 1);
			}
		}
	}
}
int main() {
	cin >> n;
	Queen(0);
	cout << ans;
}