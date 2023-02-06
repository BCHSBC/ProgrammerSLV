#include <iostream>
#include <vector>
using namespace std;
int n, k;
bool on[202];
int pw[202];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= 2 * n; i++) {
		cin >> pw[i];
	}
	int zz = 0;
	int level = 1;
	int go = 1;
	int out = n;
	while (zz < k) {
		//1
		if (out != 1) {
			out--;
		}
		else {
			out = 2 * n;
		}
		if (go != 1) {
			go--;
		}
		else {
			go = 2 * n;
		}
		if (on[out]) on[out] = false;
		//2
		int cnt = 0;
		int idx = out;
		while (cnt < n) { // n개의 자리를 탐색
			if (!on[idx]) { // 만약에 로봇이 없으면
				(idx == 1) ? idx = 2 * n : idx--;
				cnt++;
				continue;
			}
			int next_loc = (idx == 2 * n) ? 1 : idx + 1;
			if (!on[next_loc] && pw[next_loc] >= 1) {
				on[idx] = false; // 원래 자리 꺼주고
				pw[next_loc]--; // 지금 자리 마이너스
				if (pw[next_loc] == 0) zz++; // 내구도 나락
				if (next_loc == out) { // 지금 자리가 나가는 자리면
					on[idx] = false; // 나가
				}
				else {
					on[next_loc] = true; // 아니면 지금 자리 켜주고
				}
			}
			(idx == 1) ? idx = 2 * n : idx--; // 인덱스 바꿔주고
			cnt++;
		}
		//3
		if (pw[go] >= 1) {
			pw[go]--;
			if (pw[go] == 0) zz++;
			on[go] = true;
		}
		if (zz >= k) break;
		level++;
	}
	cout << level;
}