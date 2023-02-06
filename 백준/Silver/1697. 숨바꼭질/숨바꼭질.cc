#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
bool visit[100001];

int main() {
	int n, k;
	cin >> n >> k;
	if (n > k) {
		cout << n - k;
	}
	else if (n == k) {
		cout << 0;
	}
	else {
		queue <pair<int, int>> q;
		q.push({ n,0 });
		visit[n] = true;
		while (!q.empty()) {
			int node = q.front().first;
			int level = q.front().second;
			q.pop();
			if (node == k) {
				cout << level;
				return 0;
			}
			if (node + 1 <= 100000 && !visit[node+1]) {
				q.push({ node + 1,level + 1 });
				visit[node + 1] = true;
			}
			if (node - 1 >= 0 && !visit[node - 1]) {
				q.push({ node - 1,level + 1 });
				visit[node - 1] = true;
			}
			if (node * 2 <= 100000 && !visit[node * 2]) {
				q.push({ node * 2,level + 1 });
				visit[node * 2 ] = true;
			}
		}
	}
}