#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

bool bigger(queue < pair<int, int>> q) {
	int first = q.front().first;
	q.pop();
	while (!q.empty()) {
		if (q.front().first > first) {
			return true;
		}
		q.pop();
	}
	return false;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		int ans = 0;
		cin >> n >> m;
		vector < pair<int, int>> v;
		queue <pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			int number;
			cin >> number;
			q.push(make_pair(number, i));
		}
		int cnt = 1;
		while (true) {
			if (bigger(q)) {
				q.push(q.front());
				q.pop();
			}
			else {
				if (q.front().second == m) {
					ans = cnt;
					break;
				}
				q.pop();
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}