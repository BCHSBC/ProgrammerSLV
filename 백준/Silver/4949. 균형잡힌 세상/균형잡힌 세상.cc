#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

bool check(char c) {
	if (c == '[' || c == ']' || c == '(' || c == ')')
		return true;
	
	return false;
}
int main() {
	string str;
	while (true) {
		getline(cin, str);
		if (str == ".") break;
		stack <char> s;
		bool BAL = true;
		for (int i = 0; i < str.length(); i++) {
			if (check(str[i])) {
				if (str[i] == ')') {
					if (s.empty()) {
						BAL = false;
						break;
					}
					else {
						if (s.top() == '(') {
							s.pop();
						}
						else if (s.top() == '[') {
							BAL = false;
							break;
						}
					}
					
				}
				else if (str[i] == ']') {
					if (s.empty()) {
						BAL = false;
						break;
					}else {
						if (s.top() == '[') {
							s.pop();
						}
						else if (s.top() == '(') {
							BAL = false;
							break;
						}
					}
				}
				else {
					s.push(str[i]);
				}
			}
			else {
				continue;
			}
		}

		cout << (BAL ? (s.empty() ? "yes" : "no") : "no") << "\n";
	}
}