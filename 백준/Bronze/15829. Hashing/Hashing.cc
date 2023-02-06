#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	string str;
	cin >> str;
	long sum = 0;
	for (int i = 0; i < n; i++) {
		long number = (str[i] - 'a') + 1;
		long num = 1;
		int T = i;
		while (T--) {
			num = (num * 31) % 1234567891;
		}
		sum += (number * num) % 1234567891;
	}
	cout << sum;
}