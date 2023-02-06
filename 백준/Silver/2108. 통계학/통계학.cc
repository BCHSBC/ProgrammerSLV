#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int list[8002];

int main() {
	int n;
	cin >> n;
	int maxT = 0;
	int maxN = -4001;
	int minN = 4001;
	long double sum = 0;
	vector <int> v;
	int a = n;
	while (n--) {
		int number;
		cin >> number;
		v.push_back(number);
		list[number + 4000]++;
		maxT = max(maxT, list[number + 4000]);
		maxN = max(maxN, number);
		minN = min(minN, number);
		sum += number;
	}
	sort(v.begin(), v.end());
	cout << floor((sum / a) + 0.5) << "\n";
	cout << v[v.size() / 2] << "\n";
	int cnt = 0;
	int aa = 0;
	for (int i = 0; i < 8002; i++) {
		if (maxT == list[i] && cnt == 1) {
			cout << i - 4000 << "\n";
			cnt++;
			break;
		}
		if (maxT == list[i] && cnt == 0) {
			aa = i - 4000;
			cnt++;
		}
	}
	if (cnt == 1) cout << aa << "\n";
	cout << maxN - minN << "\n";
}