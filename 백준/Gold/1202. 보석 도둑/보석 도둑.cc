#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, k;
int b[300001];
pair<int, int> j[300001];
priority_queue <int> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> j[i].first >> j[i].second;
	}
	for (int i = 0; i < k; i++) {
		cin >> b[i];
	}
	sort(j, j + n);
	sort(b, b + k);

	long long res = 0;
	int index = 0;
	for (int i = 0; i < k; i++) {
		while (index < n && j[index].first <= b[i]) {
			pq.push(j[index++].second);
		}
		if (!pq.empty()) {
			res += pq.top();
			pq.pop();
		}
	}
	cout << res;
	return 0;
}
