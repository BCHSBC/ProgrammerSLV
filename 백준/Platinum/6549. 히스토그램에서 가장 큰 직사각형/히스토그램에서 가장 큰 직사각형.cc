#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
int H[100001];
vector <int> st;
int main() {
	while (true) {
		cin >> n;
		if (n == 0)break;
		for (int i = 0; i < n; i++) {
			cin >> H[i];
		}
		stack <int> s;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			while (!s.empty() && H[s.top()] > H[i]) {
				long long hh = H[s.top()];
				s.pop();
				long long w = i;
				if (!s.empty()) w = i - s.top() - 1;
				sum = max(sum, w * hh);
			}
			s.push(i);
		}

		while (!s.empty()) {
			long long h = H[s.top()];
			s.pop();
			long long w = n;
			if (!s.empty()) w = n - s.top() - 1;
			sum = max(sum, h * w);
		}
		cout << sum << "\n";
	}
}