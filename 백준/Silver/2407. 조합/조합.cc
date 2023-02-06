#include <iostream>
#include <string>
using namespace std;
string C[101][51];
string P(string a, string b) {
	string res = "";
	if (b.length() > a.length()) {
		string c = b;
		b = a;
		a = c;
	}
	int plus = 0;
	for (int i = 0; i < b.length(); i++) {
		int aa = a[a.length() - 1 - i] - '0';
		int bb = b[b.length() - 1 - i] - '0';
		int cc = aa + bb + plus;
		if (cc >= 10) {
			cc -= 10;
			res = to_string(cc) + res;
			plus = 1;
		}
		else {
			res = to_string(cc) + res;
			plus = 0;
		}
	}
	string res2 = "";
	for (int i = 0; i < a.length() - b.length(); i++) {
		int aa = a[a.length() - b.length() - 1 - i] - '0';
		int cc = aa + plus;
		if (cc >= 10) {
			cc -= 10;
			res2 = to_string(cc) + res2;
			plus = 1;
		}
		else {
			res2 = to_string(cc) + res2;
			plus = 0;
		}
	}
	if (plus == 1) {
		res = "1" + res2 + res;
	}
	else {
		res = res2 + res;
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	if (m > (n / 2)) m = n - m;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i && j<= m; j++) {
			if (i == j || j == 0) {
				C[i][j] = "1";
				continue;
			}
			if (j == 1) {
				C[i][j] = to_string(i);
				continue;
			}
			C[i][j] = P(C[i - 1][j], C[i - 1][j - 1]);
		}
	}
	cout << C[n][m];
}