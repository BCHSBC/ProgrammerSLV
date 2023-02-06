#include <iostream>
#include <algorithm>
#include <queue>
#define INF 999999999
using namespace std;
vector <pair<int, int>> adj[1001];
bool v[1001];
int d[1001];
int n, m;
int a, b, c,s,e;
void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();

		if (d[cur] < dist) continue;
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int nextDist = dist + adj[cur][i].second;

			if (d[next] > nextDist) {
				d[next] = nextDist;
				pq.push({ -nextDist,next });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}
	cin >> s >> e;
	fill(d, d + 1001, INF);
	dijkstra(s);
	cout << d[e];
}