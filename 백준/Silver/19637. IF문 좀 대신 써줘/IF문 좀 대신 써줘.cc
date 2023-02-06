#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	vector<pair<int, string>> v;
	vector <int> input;
	string str;
	int val;
	for (int i = 1; i <= N; i++) {
		cin >> str >> val;
		v.push_back({ val,str });
	}
	for (int i = 0; i < M; i++) {
		cin >> val;
		input.push_back(val);
	}
	for (int i = 0; i < input.size(); i++) {
		int s = 0, e = N - 1;
		while (s <= e) {
			int mid = (s + e) / 2;
			int value = v[mid].first;
			if (input[i] <=value) {
				e = mid - 1;
			}
			else {
				s = mid + 1;
			}
		}
		cout << v[s].second << "\n";
	}
}