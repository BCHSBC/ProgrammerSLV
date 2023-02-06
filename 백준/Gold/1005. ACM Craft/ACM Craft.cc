#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int T, N, K, S;
int t[1001];
int sum[1001];
int order[1001];
vector <int> v[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		for (int i = 0; i < 1001; i++) sum[i] = 0;
		for (int i = 0; i < 1001; i++) order[i] = 0;
		for (int i = 0; i < 1001; i++) {
			while (!v[i].empty())v[i].pop_back();
		}
		cin >> N >> K;
		for (int i = 1; i <= N; i++) cin >> t[i];
		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			order[b]++;
		}
		cin >> S;
		queue <int> q;
		for (int i = 1; i <= N; i++) {
			if (!order[i]) {
				sum[i] = t[i];
				q.push(i);
			}
		}
	
		int max_sum = 0;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (int i = 0; i < v[node].size(); i++) {
				int new_node = v[node][i];
				order[new_node]--;
				if (sum[new_node] < sum[node] + t[new_node])
					sum[new_node] = sum[node] + t[new_node];
				if (!order[new_node])
					q.push(new_node);
			}
		}
		cout << sum[S] << "\n";
	}
}