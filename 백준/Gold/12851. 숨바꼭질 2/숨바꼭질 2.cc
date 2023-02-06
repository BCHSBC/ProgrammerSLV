#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int visit[100005];
int ans = 99999999;
int cnt = 0;
int main() {
	int n, k;
	cin >> n >> k;
	if (n > k) {
		cout << n - k << "\n" << 1;
	}
	else if (n == k) {
		cout << 0 << "\n" << 1;
	}
	else {
		for (int i = 0; i <= 100000; i++) {
			visit[i] = 100000;
		}
		queue <pair<int, int>> q;
		q.push({ n,0 });
		visit[n] = 0;
		while (!q.empty()) {
			int node = q.front().first;
			int level = q.front().second;
			q.pop();
			if (level > ans) break;
			if (node == k && level <= ans) {
				ans = level;
				cnt++;
			}
			if (node + 1 <= 100000 && visit[node+1] >= level+1) {
				q.push({ node + 1,level + 1 });
				visit[node + 1] = level + 1;
			}
			if (node - 1 >= 0 && visit[node - 1]>= level+1) {
				q.push({ node - 1,level + 1 });
				visit[node - 1] = level + 1;
			}
			if (node * 2 <= 100000&& visit[node *2] >= level + 1) {
				q.push({ node * 2,level + 1 });
				visit[node * 2] = level + 1;
			}
		}
		cout << ans << "\n" << cnt;
	}
}
