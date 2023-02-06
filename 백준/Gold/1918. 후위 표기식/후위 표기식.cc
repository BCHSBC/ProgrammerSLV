#include <iostream>
#include <string>
#include <stack>
using namespace std;

int rk(string s) {
	if (s == "+" || s == "-")return 1;
	else return 2;
}
bool check(string s) {
	if (s == "+" || s == "-" || s == "*" || s == "/")
		return true;
	
	return false;
}
bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second) return rk(a.first) >= rk(b.first);
	else return a.second >= b.second;
}
int main() {
	string ans = "";
	stack <string> a;
	stack <pair<string,int>> b;

	string str;
	cin >> str;
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		ans = "";
		char c = str[i];
		string s = "";
		s.push_back(c);
		pair<string, int> tp = { s,cnt };
		if (check(s)) {
			while (!b.empty() && cmp(b.top(),tp)) {
				ans = "";
				ans = ans + b.top().first; b.pop();
				ans = a.top() + ans; a.pop();
				ans = a.top() + ans; a.pop();
				a.push(ans);
			}
			b.push(tp);
		}
		else {
		if (s == "(") {
			a.push(s);
			cnt++;
		}
		else if (s == ")") {
			while (a.top() != "(") {
				if (b.empty() || cnt != b.top().second) {
					ans = a.top(); a.pop();
				}
				else {
					ans = "";
					ans = ans + b.top().first; b.pop();
					ans = a.top() + ans; a.pop();
					ans = a.top() + ans; a.pop();
					if (a.top() != "(") {
						a.push(ans);
					}
				}
			}
			a.pop();
			a.push(ans);
			cnt--;
		}
		else {
				a.push(s);
		}
		}
	}
	while (!b.empty()) {
		ans = "";
		ans = ans + b.top().first; b.pop();
		ans = a.top() + ans; a.pop();
		ans = a.top() + ans; a.pop();
		a.push(ans);
	}
	cout << a.top();
}