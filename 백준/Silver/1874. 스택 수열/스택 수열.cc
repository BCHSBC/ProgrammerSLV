#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;



int main() {
	int n;
	cin >> n;
	vector <int> v;
	stack <int> s;
	queue <int> q;
	vector <char> ans;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		v.push_back(number);
		q.push(i + 1);
	}
	int prev = 0;
	bool IMPOS = false;
	for (int i = 0; i < v.size(); i++) {
		int number = v[i];
		if (prev > number) {
			while (true) {
				if (s.empty()) {
					IMPOS = true;
					break;
				}
				prev = s.top();
				s.pop();
				ans.push_back('-');
				if (prev == number) break;
			}
		}
		else if (prev < number) {
			while (true) {
				if (q.empty()) {
					IMPOS = true;
					break;
				}
				prev = q.front();
				s.push(prev);
				q.pop();
				ans.push_back('+');
				if (prev == number) {
					s.pop();
					ans.push_back('-');
					break;
				}
			}
		}
		if (IMPOS) break;
	}
	if (IMPOS) cout << "NO";
	else {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}
	}
}

