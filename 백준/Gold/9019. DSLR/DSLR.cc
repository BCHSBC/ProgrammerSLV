#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int before, after;
		cin >> before >> after;
		bool check[10001];
		for (int i = 0; i < 10001; i++) {
			check[i] = false;
		}
		queue <pair<int, string>> q;
		q.push({ before,""});
		while (!q.empty()) {
			pair<int,string> front = q.front();
			q.pop();
			// 비포 애프터가 같을 경우 커맨드를 나열 후 나가기
			if (front.first == after) {
				cout << front.second << "\n";
				break;
			}
			//D
			int d_number = (front.first * 2) % 10000;
			if (!check[d_number]) {
				check[d_number] = true;
				q.push({ d_number,front.second + "D" });
			}
			//S
			int s_number = !(front.first) ? 9999 : front.first - 1;
			if (!check[s_number]) {
				check[s_number] = true;
				q.push({ s_number,front.second + "S" });
			}
			//L
			int l_number = (front.first % 1000) * 10 + (front.first / 1000);
			if (!check[l_number]) {
				check[l_number] = true;
				q.push({ l_number,front.second + "L" });
			}
			int r_number = (front.first % 10) * 1000 + (front.first / 10);
			if (!check[r_number]) {
				check[r_number] = true;
				q.push({ r_number,front.second + "R" });
			}
		}
	}
}