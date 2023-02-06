#include <iostream>
#include <vector>
using namespace std;

int T, N;
int L[1000001];
int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		long long  sum = 0;
		long long profit = 0;
		long long  number = 0;
		long long  max_prev = 0;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			cin >> L[i];
		}
		for (int i = N - 1; i >= 0; i--) {
			if (L[i] <= max_prev) {
				profit += max_prev - L[i];
			}
			else {
				max_prev = L[i];
			}
		}
		cout << profit << "\n";
	}
}