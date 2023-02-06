#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool F[5001][5001];
bool C[5001];
int L[5001];
int n, m;
int BFS(int node) {
	queue <pair<int, int>> q;
	q.push({ node,0 });
	C[node] = true;
	while (!q.empty()) {
		int front = q.front().first;
		int level = q.front().second;
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (F[front][i] && !C[i]) {
				C[i] = true;
				q.push({ i,level + 1 });
				L[node] += level + 1;
			}
		}
	}
	return L[node];
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		F[a][b] = true;
		F[b][a] = true;
	}
	int minLevel = 99999;
	int minIndex = 0;
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= n; j++) {
			C[j] = false;
		}
		int res = BFS(i);
		if (res < minLevel) {
			minLevel = res;
			minIndex = i;
		}
	}
	cout << minIndex;
}