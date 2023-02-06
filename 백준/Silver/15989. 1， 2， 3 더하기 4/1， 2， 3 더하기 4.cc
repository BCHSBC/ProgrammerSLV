#include <iostream>
using namespace std;
int S[10001][4];
int A[10001];
int main() {
	int T, N;
	cin >> T;
	S[1][1] = 1;
	S[2][1] = 1;
	S[2][2] = 1;
	S[3][1] = 1;
	S[3][2] = 1;
	S[3][3] = 1;
	for (int i = 4; i <= 10000; i++) {
		S[i][1] = S[i - 1][1];
		S[i][2] = S[i - 2][1] + S[i - 2][2];
		S[i][3] = S[i - 3][1] + S[i - 3][2] + S[i - 3][3];
	}
	while (T--) {
		cin >> N;
		cout << S[N][1] + S[N][2] + S[N][3] << "\n";
	}
}