#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;
int n, m;
int L[1001][1001];
int dp[1001][1001][2];
bool visited[1001][1001][2];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int FIND(int x, int y, int crack) {
	visited[x][y][crack] = true;
	queue<pair<tuple<int, int, int>, int>> q;
	q.push({ make_tuple(x,y,1),0 });
	int ans = -1;
	while (!q.empty()) {
		pair<tuple<int, int, int>, int> p = q.front();
		q.pop();
		tuple<int, int, int> t = p.first;
		int crack = p.second;
		if (get<0>(t) == n && get<1>(t) == m) {
			ans = 	get<2>(t);
			break;
		}
		for (int i = 0; i < 4; i++) {
			int new_x = get<0>(t) + dx[i];
			int new_y = get<1>(t) + dy[i];
			if (new_x < 1 || new_x > n || new_y <1 || new_y > m) continue;
			if (!visited[new_x][new_y][crack]) {
				if (crack == 0 && L[new_x][new_y] == 1) {
					visited[new_x][new_y][1] = true;
					q.push({ make_tuple(new_x,new_y,get<2>(t) + 1),1 });
				}
				if (L[new_x][new_y] == 0) {
					visited[new_x][new_y][crack] = true;
					q.push({ make_tuple(new_x,new_y,get<2>(t) + 1),crack });
				}
			}
		}
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <=n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			L[i][j+1] = s[j]-'0';
		}
	}
	cout << FIND(1, 1, 0);

}