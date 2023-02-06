#include <iostream>
using namespace std;
char map[3073][6145];
void STAR(int x,int y,int n) {
	if (n == 3) {
		map[x][y] = '*';
		map[x + 1][y - 1] = map[x + 1][y + 1] = '*';
		for (int i = 0; i < 5; i++) {
			map[x + 2][y - 2 + i] = '*';
		}
		return;
	}
	STAR(x, y, n / 2);
	STAR(x + n/2, y - n / 2, n / 2);
	STAR(x + n/2, y + n / 2, n / 2);
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 3073; i++) {
		for (int j = 0; j < 6145; j++) {
			map[i][j] = ' ';
		}
	}
	STAR(0,n-1,n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n-1; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	return 0;
}