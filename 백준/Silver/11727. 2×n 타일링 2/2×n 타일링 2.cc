#include <iostream>
using namespace std;

int list[1001];

int main() {
	int n;
	cin >> n;
	list[1] = 1;
	list[2] = 3;
	for (int i = 3; i <= n; i++) {
		list[i] = (list[i - 1] + (2 * list[i - 2])%10007)%10007;
	}
	cout << list[n];
}