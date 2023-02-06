#include <iostream>
#include <vector>
using namespace std;
bool check[1001];
int n, m;
vector <vector<int>> v(1001);
void DFS(int number) {
	for (int i = 0; i < v[number].size(); i++) {
		int nNum = v[number][i];
		if (!check[nNum]) {
			check[nNum] = true;
			DFS(nNum);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			DFS(i);
			answer++;
		}
 	}
	cout << answer;
}