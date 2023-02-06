#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool joah[2001];
int main() {
	int n;
	cin >> n;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		int y;
		cin >> y;
		v.push_back(y);
	}
	sort(v.begin(), v.end());
	int nas = 0;

	for (int i = 0; i < v.size(); i++) {
		int start = 0;
		int end = v.size()-1;
		bool fin = false;
		while (start < end) {
			int sum = (v[start] + v[end]);
			int mid = (start + end) / 2;
			if (start == i) {
				start++;
				continue;
			}
			if (end == i) {
				end--;
				continue;
			}
			if (sum == v[i]) {
				fin = true;
			//	cout << sum << "\n";
				break;
			}
			if (sum <= v[i]) {
				start ++;
			}
			if (sum > v[i]){
				end --;
			}
		}
		if (fin)nas++;
	}
	cout << nas;
}