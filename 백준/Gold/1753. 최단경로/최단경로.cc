#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int V, E, k, u, v, w;
int INF = 987654321;
vector <pair<int, int>> vtr[20001];
int d[20001];
void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int distance = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (d[cur] < distance) continue;
		for (int i = 0; i < vtr[cur].size(); i++) {
			int nextDistance = distance+vtr[cur][i].first;
			int next = vtr[cur][i].second;

			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push({ -nextDistance, next });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> V >> E >> k;
	for (int i = 1; i <= V; i++) {
		d[i] = INF;
	}
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		vtr[u].push_back({ w,v });
	}
	dijkstra(k);
	for (int i = 1; i <= V; i++) {
		if (d[i] == 987654321)cout << "INF" << "\n";
		else
		cout << d[i] << "\n";
	}
}