#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
int list[101][101][101]; // 세로 가로 높이
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0,0,0,0,-1,1 };
int m, n, h;
bool check[101][101][101];
vector <tuple<int, int, int>> v;
bool Check(int number,int limit) {
	if (number < 0 || number >= limit)return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> h;
	int sum = 0;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> list[i][j][k];
				if (list[i][j][k] == 0)sum++;
				if (list[i][j][k] == 1) {
					check[i][j][k] = true;
					v.push_back(make_tuple(i, j, k));
				}
			}
		}
	}
	queue <pair<tuple<int, int, int>, int>> q;
	for (int i = 0; i < v.size(); i++) {
		q.push({ v[i],0 });
	}
	int answer = -1;
	while (!q.empty()) {
		tuple <int, int, int> t = q.front().first;
		int level = q.front().second;
		q.pop();
		answer = level;
		for (int i = 0; i < 6; i++) {
			int new_x = get<0>(t) + dx[i];//세로
			int new_y = get<1>(t) + dy[i];//가로
			int new_z = get<2>(t) + dz[i];

			if (Check(new_x,m) || Check(new_y,n) || Check(new_z,h)) continue;

			if (!check[new_x][new_y][new_z] && list[new_x][new_y][new_z] == 0) {
				check[new_x][new_y][new_z] = true;
				list[new_x][new_y][new_z] = 1;
				sum--;
				q.push({ make_tuple(new_x,new_y,new_z),level + 1 });
			}
		}
	}
	if (sum != 0) answer = -1;
	cout << answer;
	
}