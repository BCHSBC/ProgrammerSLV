#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n;
int newN;
vector <pair<int, int>> v[100001];
int BFS(int number) {
	int maxlen = 0;
	bool check[100001] = { false };
	check[number] = true;
	queue <pair<int, int>> q;
	q.push({ number,0 });
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		if (maxlen < p.second) {
			maxlen = p.second;
			newN = p.first;
		}
		for (int i = 0; i < v[p.first].size(); i++) {
			int nn = v[p.first][i].first;
			int len = v[p.first][i].second;
			if (check[nn])continue;
			check[nn] = true;
			q.push({ nn,len + p.second });
		}
	}
	return maxlen;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		int cnt = 0;
		int tmp = 0;
		while (1) {
			int nmp;
			cin >> nmp;
			if (nmp == -1) break;
			if (cnt % 2 == 0) {
				tmp = nmp;
			}
			else {
				v[number].push_back({ tmp,nmp });
			}
			cnt++;
		}
	}
	int ans = 0;
	ans = max(ans,BFS(1));
	ans = max(ans,BFS(newN));
	cout << ans;
}