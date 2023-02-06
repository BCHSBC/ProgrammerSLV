#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
int n;
int list[26][26];
bool check[26][26];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<pair<int, int>> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '1') {
				list[i][j] = 1; 
				v.push_back({ i,j });
			}
		}
	}
	vector< int> vv;
	for (int i = 0; i < v.size(); i++) {
		if (!check[v[i].first][v[i].second]) {
			int count = 1;
			check[v[i].first][v[i].second] = true;
			queue<pair<int, int>> q;
			q.push({ v[i].first,v[i].second });
			while (!q.empty()) {
				pair<int, int> p = q.front();
				q.pop();
				for (int j = 0; j < 4; j++) {
					int new_x = p.first + dx[j];
					int new_y = p.second + dy[j];

					if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= n) continue;

					if (list[new_x][new_y] == 1 && !check[new_x][new_y]) {
						check[new_x][new_y] = true;
						count++;
						q.push({ new_x,new_y });
					}
				}
			}
			vv.push_back(count);
		}
	}
	sort(vv.begin(), vv.end());
	cout << vv.size() << "\n";
	for (int i = 0; i < vv.size(); i++) {
		cout << vv[i] << "\n";
	}
}