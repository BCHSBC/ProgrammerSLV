#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	cin.ignore();
	stack <int> s;
	while (N > 0) {
		string command;
		getline(cin, command);
		
		if (command.length() >= 6) {
			string str = command.substr(5);
			s.push(stoi(str));
		}
		if (command == "top") {
			if (s.empty()) cout << -1 << "\n";
			else cout << s.top() << "\n";
		}
		if (command == "size") {
			cout << s.size() << "\n";
		}
		if (command == "empty") {
			cout << s.empty() << "\n";
		}
		if (command == "pop") {
			if (s.empty()) cout << -1 << "\n";
			else {
				cout << s.top() << "\n";
				s.pop();
			}
		}
		N--;
	}
}

