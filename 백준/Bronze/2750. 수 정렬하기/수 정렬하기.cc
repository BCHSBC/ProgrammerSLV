#include <iostream>
using namespace std;
int list[1001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j > 0; j--) {
			if (list[j - 1] > list[j]) {
				swap(list[j - 1], list[j]);
			}
			else
			{
				continue;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << list[i] << "\n";
	}
}