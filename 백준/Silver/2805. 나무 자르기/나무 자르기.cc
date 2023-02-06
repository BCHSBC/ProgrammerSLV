#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long n, m;
	cin >> n >> m;
	vector <int> v;
	int maxT = 0;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		v.push_back(number);
		maxT = max(maxT, number);
	}
	long left = 0;
	long  right = maxT;


	while (left <= right) {
		long mid = (left + right) / 2;
		long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += max(long(0), v[i] - mid);
		}
		if (sum >= m) {
			left = mid + 1;
		}
		else {
			right = mid-1;
		}
	}
	cout << left -1;
	
}