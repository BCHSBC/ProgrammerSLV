#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int a[10001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while (n--) {
		int number;
		cin >> number;
		a[number]++;

	}
	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < a[i]; j++) {
			cout << i << "\n";
		}
	}
}