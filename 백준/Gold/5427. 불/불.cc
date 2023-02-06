#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int w, h;
char L[1001][1001];
bool V1[1001][1001];
bool V2[1001][1001];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector <pair<int, int>> v;
pair<int, int> s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T>0) {
		T--;
		v.clear();
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < str.length(); j++) {
				L[i][j] = str[j];
				if (str[j] == '*') {
					v.push_back({ i,j });
				}
				if (str[j] == '@')s = { i,j };
				V1[i][j] = V2[i][j] = false;
			}
		}	
		queue <pair<pair<int, int>, pair<int, int>>> q;
		V1[s.first][s.second] = true;
		for (int i = 0; i < v.size(); i++) {
			V2[v[i].first][v[i].second] = true;
			q.push({ v[i],{1,0} });
		}
		q.push({ s,{0,0} });
		bool findans = false;
		while (!q.empty()) {
			pair<int, int> p = q.front().first;
			int flag = q.front().second.first;
			int t = q.front().second.second;

			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = p.first + dx[i];
				int ny = p.second + dy[i];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
					if (flag == 0) {
						cout << t + 1 << "\n";
						findans = true;
						break;
					}
					else continue;
				}
				if (flag == 0) {
					if (!V1[nx][ny] && !V2[nx][ny] && L[nx][ny] == '.') {
						V1[nx][ny] = true;
						q.push({ {nx,ny},{0,t + 1} });
					}
				}
				else {
					if (!V2[nx][ny] && L[nx][ny] != '#') {
						V2[nx][ny] = true;
						q.push({ {nx,ny},{1,t + 1} });
					}
				}
			}
			if (findans)break;
		}
		while (!q.empty())q.pop();
		if (!findans) cout << "IMPOSSIBLE" << "\n";
	}

}