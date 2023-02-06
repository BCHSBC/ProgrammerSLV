#include <iostream>
#include <stack>
using namespace std;
int L[1000001];
int A[1000001];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> L[i];
	stack <pair<int, int>> s;

	for (int i = 0; i < N; i++) {
		while (!s.empty() && s.top().first < L[i]) {
			A[s.top().second] = L[i];
			s.pop();
		}
		s.push({ L[i],i });
	}
	for (int i = 0; i < N; i++)cout << ((A[i] == 0) ? -1 : A[i]) << " ";
}