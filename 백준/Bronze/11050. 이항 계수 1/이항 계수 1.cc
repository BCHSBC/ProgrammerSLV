#include <iostream>
using namespace std;

int main() {
	int C[11][11];
	
	for (int i = 1; i <= 10; i++) {
		C[i][0] = 1;
		C[i][1] = i;
		C[i][i] = 1;
		for (int j = 1; j < i; j++) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	int n, k;
	cin >> n >> k;
	cout << C[n][k];
}