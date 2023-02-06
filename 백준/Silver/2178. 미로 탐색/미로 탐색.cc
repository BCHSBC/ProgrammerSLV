#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>
#include <queue>
using namespace std;

int n, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int list[101][101];
bool check[101][101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '0') list[i][j] = 0;
			else list[i][j] = 1;
		}
	}
	queue < tuple<int, int, int >> q;
	q.push(make_tuple(0, 0, 0));
	check[0][0] = true;
	int answer = 0;
	while (!q.empty()) {
		tuple <int, int, int> t = q.front();
		q.pop();
		if (get<0>(t) == n-1 && get<1>(t) == m-1) {
			answer = get<2>(t);
			break;
		}
		for (int i = 0; i < 4; i++) {
			int new_x = get<0>(t) + dx[i];
			int new_y = get<1>(t) + dy[i];

			if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= m) continue;

			if (list[new_x][new_y] == 1 && !check[new_x][new_y]) {
				check[new_x][new_y] = true;
				q.push(make_tuple(new_x, new_y, get<2>(t) + 1));
			}
		}
	}
	cout << answer+1;
}