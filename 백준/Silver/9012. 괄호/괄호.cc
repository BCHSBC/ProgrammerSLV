#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		stack <char> s;
		for (int i = 0; i < str.length(); i++) {
			if (!s.empty()) {
				if (s.top() != str[i] && str[i] == ')') {
					s.pop();
				}
				else {
					s.push(str[i]);
				}
			}
			else {
				s.push(str[i]);
			}
		}
		if (s.empty()) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}