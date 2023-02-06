#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int f, s, g, u, d;

int L[1000001];
bool V[1000001];
void SLV() {
	bool flag = false;
	queue <pair<int,int>> q;
	V[s] = true;
	q.push({ s,0 });
	while (!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cur == g) {
			cout << cnt;
			flag = true;
			break;
		}
		int up = cur + u;
		if (up <= f && !V[up]) {
			q.push({ up,cnt + 1 });
			V[up] = true;
		}
		int down = cur - d;
		if (down >= 1 && !V[down]) {
			V[down] = true;
			q.push({ down,cnt + 1 });
		}
	}
	if (!flag)cout << "use the stairs";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> f >> s >> g >> u >> d;
	if (s == g) cout << 0;
	else if (s > g) {
		if (d == 0) cout << "use the stairs";
		else {
			SLV();
		}
	}
	else {
		if (u == 0) cout << "use the stairs";
		else {
			SLV();
		}
	}
}