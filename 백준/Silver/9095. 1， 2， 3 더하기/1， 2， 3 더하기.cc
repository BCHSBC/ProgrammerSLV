#include <iostream>
using namespace std;
int ans = 0;
void DFS(int number,int t,int cnt) {
	if (t == number) {
		ans++;
	}
	if (t > number)return;
	DFS(number, t + 1,cnt+1);
	DFS(number, t + 2,cnt+1);
	DFS(number, t + 3,cnt+1);
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		ans = 0;
		DFS(number,0,0);
		cout << ans << "\n";
	}
}