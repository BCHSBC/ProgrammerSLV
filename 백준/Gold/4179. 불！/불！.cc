#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int r, c;
char L[1001][1001];
bool VJ[1001][1001];
bool VF[1001][1001];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue <pair<pair<int, int>,pair<int, int>>> q;
pair<int, int> J;
pair<int, int> F;
vector <pair<int, int>> FF;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			L[i][j] = str[j];
			if (str[j] == 'J') {
				J = { i,j };
			}
			if (str[j] == 'F') {
				FF.push_back({ i,j });
			}
		}
	}
	VJ[J.first][J.second] = true;
	q.push({ {J.first,J.second},{0,0} });
	for (int i = 0; i < FF.size(); i++) {
		VF[FF[i].first][FF[i].second] = true;
		q.push({ {FF[i].first,FF[i].second},{1,0} });
	}
	while (!q.empty()) {
		bool out = false;
		pair<int, int> loc = q.front().first;
		int flag = q.front().second.first;
		int t = q.front().second.second;
		q.pop();
		if (flag == 0)if (VF[loc.first][loc.second])continue;
		for (int i = 0; i < 4; i++) {
			int nx = loc.first + dx[i];
			int ny = loc.second + dy[i];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
				if (flag == 0) {
					cout << t + 1;
					exit(0);
				}
				else {
					continue;
				}
			}
			if (flag == 0) {
				if (L[nx][ny] == '.' && !VF[nx][ny] && !VJ[nx][ny]) {
					VJ[nx][ny] = true;
					q.push({ {nx,ny},{flag,t + 1} });
				}
			}
			else {
				if (L[nx][ny] != '#' && !VF[nx][ny]) {
					VF[nx][ny] = true;
					q.push({ {nx,ny},{flag,t + 1} });
				}
			}
		}
		
	}
	cout << "IMPOSSIBLE";
}