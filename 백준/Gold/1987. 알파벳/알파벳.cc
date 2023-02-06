#include <iostream>
#include <vector>
using namespace std;
int r, c;
int L[21][21];
bool check[26];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ans = 0;
void DFS(int x, int y,int Len) {
	ans = max(ans, Len);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if (!check[L[nx][ny]]) {
			check[L[nx][ny]] = true;
			DFS(nx, ny, Len + 1);
			check[L[nx][ny]] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			L[i][j] = str[j] - 'A';
		}
	}
	check[L[0][0]] = true;
	DFS(0, 0,1);
	cout << ans;
}