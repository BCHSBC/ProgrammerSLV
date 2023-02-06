#include <iostream>
#include <stack>
using namespace std;
long H[500001];

long A[500001];
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> H[i];
	}
	stack <pair<int,int>> s;
	for (int i = N; i >= 1; i--) {
		if (s.empty()) s.push({i, H[i]});
		else {
			while (!s.empty() && s.top().second < H[i]) {
				A[s.top().first] = i;
				s.pop();
			}
			s.push({ i,H[i] });
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << A[i] << " ";
	}
}