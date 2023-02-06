#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool C[1001][1001];
bool check[1001];

void DFS(int node) {
	cout << node << " ";
	check[node] = true;
	for (int i = 0; i < 1001; i++) {
		if (C[node][i] && !check[i]) {
			DFS(i);
		}
	}
}
void BFS(int node) {
	queue <int> q;
	q.push(node);
	check[node] = true;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		cout << front << " ";
		for (int i = 0; i < 1001; i++) {
			if (C[front][i] && !check[i]) {
				q.push(i);
				check[i] = true;
			}
		}

	}
}
int main() {
	int n, m, v;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		C[a][b] = true;
		C[b][a] = true;
	}
	DFS(v);
	cout << "\n";
	for (int i = 0; i < 1001; i++) {
		check[i] = false;
	}
	BFS(v);
}