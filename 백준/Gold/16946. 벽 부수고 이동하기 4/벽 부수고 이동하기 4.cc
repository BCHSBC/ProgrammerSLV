#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
using namespace std;
int n, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int mp[1001][1001];
int mp2[1001][1001];
map <int, int> mm;
bool visited[1001][1001];
int pcount = 0;
int DFS(int x, int y, int party) {
	int res = 1;
	mp2[x][y] = party;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
		if (!visited[nx][ny] && mp[nx][ny] == 0) {
			visited[nx][ny] = true;
			res += DFS(nx, ny, party);
		}
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			mp[i][j] = s[j]-'0';
		}
	}
	int party = 2;
	for (int i = 0; i < n; i++) {
		for(int j = 0;j<m;j++){
			if (mp[i][j] == 0 && !visited[i][j])
			{
				pcount = 0;
				visited[i][j] = true;
				int zcount = DFS(i, j, party);
				//cout << party << "   " << zcount << "\n";
				mm[party++] = zcount;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mp[i][j] == 1) {
				int sum = 1;
				set <int> s;
				for (int x = 0; x < 4; x++) {
					int nx = i + dx[x];
					int ny = j + dy[x];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
					if (mp[nx][ny] == 0) {
						int p = mp2[nx][ny];
						s.insert(p);
					}
				}
				set<int>::iterator iter;
				for (iter = s.begin(); iter != s.end(); iter++) {
					sum += mm[*iter];
				}
				mp[i][j] = sum%10;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mp[i][j];
		}
		cout << "\n";
	}
}