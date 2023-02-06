#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int k, n;
	cin >> k >> n;
	vector <long long> v;
	for (int i = 0; i < k; i++) {
		int number;
		cin >> number;
		v.push_back(number);
	}
	sort(v.begin(), v.end());
	long long right = v[v.size()-1];
	long long left = 1;
	while (left <= right) {
		int count = 0;
		long long  mid = (right + left) / 2;
		for (int i = 0; i < k; i++) {
			count += v[i] / mid;
		}
		if (count < n) {
			right = mid-1;
		}
		else {
			left = mid+1;
		}
	}
	cout << right;
}