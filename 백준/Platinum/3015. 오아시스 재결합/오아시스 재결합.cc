#include <iostream>
#include <stack>
using namespace std;

int N;
long long  L[500001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> L[i];
	}
	stack <pair<long long,long long> > s;
	long long  ans = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		while (!s.empty() && s.top().first < L[i]) {
			ans += s.top().second;
			s.pop();
		}
		int h = 1;
		if (!s.empty()) {
			if (s.top().first == L[i]) {
				ans += s.top().second;
				h = s.top().second + 1;
				if (s.size() > 1)ans++;
				s.pop();
			}
			else {
				ans++;
			}
		}
		s.push({ L[i],h });
	}
	cout << ans;
}