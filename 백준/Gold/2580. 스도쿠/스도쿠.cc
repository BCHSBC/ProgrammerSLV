#include <iostream>
#include <vector>
using namespace std;
int sudo[9][9];
vector <pair<int, int>> v;
bool pos(pair<int, int> p, int number) {
	int n = p.first;
	int m = p.second;
	for (int i = 0; i < 9; i++) {
		if (sudo[n][i] == number) {
			return false;
		}
		if (sudo[i][m] == number) {
			return false;
		}
	}
	int h = (n / 3) * 3;
	int w = (m / 3) * 3;
	for (int i = h; i < h + 3; i++) {
		for (int j = w; j < w + 3; j++) {
			if (sudo[i][j] == number)
				return false;
		}
	}
	return true;
}
void SLV(int cnt) {
	if (cnt == v.size())
	{
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudo[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	for (int i = 1; i <= 9; i++) {
		if (pos(v[cnt], i)) {
			sudo[v[cnt].first][v[cnt].second] = i;
			SLV(cnt + 1);
			sudo[v[cnt].first][v[cnt].second] = 0;
		}
	}
}
int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudo[i][j];
			if (sudo[i][j] == 0) {
				v.push_back({ i,j });
			}
		}
	}
	SLV(0);
}