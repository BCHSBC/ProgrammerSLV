#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, k;
bool visit[100001];
int dp[100001];
int FIND(int start) {
	visit[n] = true;
	priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int> >> p;
	p.push({ 0,n });
	while (!p.empty()) {
		pair <int, int> pa = p.top();
		p.pop();
		if (pa.second == k) {
			return pa.first;
		}
		if (2 * pa.second <= 100000&& !visit[2*pa.second]) {
			visit[2 * pa.second] = true;
			p.push({ pa.first,2 * pa.second });
		}
		if (!visit[pa.second + 1] && pa.second + 1 <= 100000) {
			visit[pa.second + 1] = true;
			p.push({ pa.first + 1,pa.second + 1 });
		}
		if ( pa.second - 1 >= 0&& !visit[pa.second -1]) {
			visit[pa.second -1] = true;
			p.push({ pa.first + 1,pa.second - 1 });
		}
	}
}
int main() {
	cin >> n >> k;
	if (n == k) {
		cout << 0;
	}
	else if (n > k) {
		cout << n - k;
	}
	else {
		cout << FIND(n);
	}
}