#include <iostream>
using namespace std;
int list[1001];
int main() {
	list[1] = 1;
	list[2] = 2;
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		list[i] = (list[i - 1] + list[i - 2])%10007;
	}
	cout << list[n];
}