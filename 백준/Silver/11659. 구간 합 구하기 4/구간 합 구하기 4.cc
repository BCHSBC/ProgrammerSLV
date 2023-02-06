#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long int n, m;
	cin >> n >> m;
	vector <long long int> v;
	v.push_back(0);
	for (int i = 1; i <= n; i++) {
		long long int number;
		cin >> number;
		v.push_back(number + v.back());
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << v[b] - v[a - 1] << "\n";
	}
}