#include <iostream>
#include <vector>
using namespace std;
int L[100001];
int n, s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> s;
	int start = 0, end = 0;
	long long sum = 0;
	vector <long long> v;
	for (int i = 0; i < n; i++) {
		cin >> L[i];
	}
	int len = 100001;
		sum = 0;
		while (end <= n) {
			if (sum < s) {
				sum += L[end++];
			}
			else if (sum >= s) {
				len = min(len, end - start);
				sum -= L[start++];
			}
		}
		if (len == 100001) cout << 0;
		else cout << len;
	
}