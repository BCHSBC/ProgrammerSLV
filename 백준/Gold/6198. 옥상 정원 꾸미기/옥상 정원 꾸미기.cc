#include <iostream>
#include <stack>
using namespace std;
int L[80001];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> L[i];
	}
	stack <int> s;
	long long  sum = 0;
	for (int i = 0; i < N; i++) {
		while (!s.empty() && s.top() <= L[i]) {
			s.pop();
		}
		s.push(L[i]);
		sum += (s.size() - 1);
	}
	cout << sum;
}