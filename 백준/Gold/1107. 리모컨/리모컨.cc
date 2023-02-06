#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int n, m;
bool button[10];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 10; i++) {
		button[i] = true;
	}
	cin >> n >> m;
	int k = n;
	int h = 0;
	while (k / 10 >= 1) {
		h++;
		k /= 10;
	}
	for (int i = 0; i < m; i++) {
		int number;
		cin >> number;
		button[number] = false;
	}
	int diff = 999999;
	int x = -999999;
	int minplus = 10;
	for (int i = 0; i <= 999999; i++) {
		string str = to_string(i);
		bool POS = true;
		for (int i = 0; i < str.length(); i++) {
			if (!button[str[i] - '0']) {
				POS = false;
				break;
			}
		}
		if (!POS) continue;
		int xx = i;
		int plus = 0;
		while (xx / 10 >= 1) {
			plus++;
			xx /= 10;
		}
		plus++;
		int total = abs(n - i) + plus;
		if (diff > total) {
			diff = total;
			x = i;
		}
	}
	int xx = x;
	int plus = 0;
	while (xx / 10 >= 1) {
		plus++;
		xx /= 10;
	}
	if (n == 100) {
		cout << 0;
	}
	else {
		cout << min(abs(n - 100), plus+1 + abs(n - x));
	}
}