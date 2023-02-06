#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int n, m;
int list[51][51];
bool st[14];
vector <pair<int, int>> ck;
vector <pair<int, int>> house;
int minAns = 2147483647;
int CAL() {
	int sum = 0;
	for (int i = 0; i < house.size(); i++) {
		int minVal = 2147483647;
		for (int j = 0; j < ck.size(); j++) {
			if (st[j] == true)
				minVal = min(minVal, abs(house[i].first - ck[j].first) + abs(house[i].second - ck[j].second));
			else continue;
		}
		sum += minVal;
		if (sum > minAns) return 2147483647;
	}
	return sum;
}
void SLV(int cnt, int idx) {

	if (cnt == m) {
		minAns = min(minAns,CAL());
		return;
	}
	else {
		for (int i = idx + 1; i < ck.size(); i++) {
			st[i] = true;
			SLV(cnt + 1, i);
			st[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> list[i][j];
			if (list[i][j] == 2) {
				ck.push_back({i,j});
			}
			if (list[i][j] == 1) {
				house.push_back({ i,j });
			}
		}
	}
	SLV(0, -1);
	cout << minAns;

}