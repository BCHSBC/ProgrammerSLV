#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, d, k, c;
vector <int> v;
int eat[3001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	for (int i = 0; i < k; i++) {
		v.push_back(v[i]);
	}
	int start = 0, end = k;
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		if (!eat[v[i]]) {
			eat[v[i]] ++;
			cnt++;
		}
		else {
			eat[v[i]]++;
		}
	}
	int maxV = cnt;
	for (int i = k; i < v.size() - 1; i++) {
		eat[v[i - k]]--;
		if (eat[v[i - k]] == 0) cnt--;
		if (eat[v[i]] == 0) {
			eat[v[i]]++;
			cnt++;
		}
		else {
			eat[v[i]]++;
		}
		if (eat[c] == 0)
			maxV = max(maxV, cnt + 1);
		else
			maxV = max(maxV, cnt);
	}
	cout << maxV;
}