#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m;
int jump[101];
int check[101];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		int a, b;
		cin >> a >> b;
		jump[a] = b;
	}
	queue<pair<int, int>> q;
	q.push({ 1,0 });
	while (!q.empty()) {
		pair <int, int> p = q.front();
		q.pop();
		if (p.first == 100) {
			cout << p.second;
			return 0;
		}
		for (int i = 1; i <= 6; i++) {
			int np = p.first + i;
			if (np >= 101) continue;
			if (jump[np] != 0) np = jump[np];
			if (check[np]) continue;
			
			check[np] = true;
			q.push({ np,p.second + 1 });
		}
	}
}