#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector <int> v[100001];
int p[100001];
queue <int> q;
bool check[100001];
void FIND(int node) {
	q.push(1);
	check[1] = true;
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		for (int i = 0; i < v[top].size(); i++) {
			int pp = v[top][i];
			if (!check[pp]) {
				check[pp] = true;
				p[pp] = top;
				q.push(pp);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	FIND(1);
	for (int i = 2; i <= n; i++) {
		cout << p[i] << "\n";
	}
}