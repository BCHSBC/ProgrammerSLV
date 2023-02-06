#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.first > b.first) return false;
	else if (a.first == b.first) return a.second < b.second;
	else return true;
}

int main() {
	int N;
	cin >> N;
	vector <pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}