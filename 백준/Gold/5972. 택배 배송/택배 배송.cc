#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 99999999
using namespace std;
int N, M;
vector <pair<int, int>> v[50001];
vector <int> dijkstra(int start) {
	vector <int> dist(N, INF);
	priority_queue <pair<int, int>> pq;

	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur_idx = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[cur_idx].size(); i++) {
			int nx_idx = v[cur_idx][i].first;
			int nx_dist = cur_dist + v[cur_idx][i].second;

			if (nx_dist < dist[nx_idx]) {
				dist[nx_idx] = nx_dist;
				pq.push({ -nx_dist,nx_idx });
			}
		}
	}
	return dist;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		v[s-1].push_back({ e-1,c });
		v[e-1].push_back({ s-1,c });
	}
	vector <int> dist = dijkstra(0);
	cout << dist[N - 1];
}