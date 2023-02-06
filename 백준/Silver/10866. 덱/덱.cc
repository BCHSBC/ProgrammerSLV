#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	cin.ignore();
	deque <int> s;
	while (N > 0) {
		string command;
		getline(cin, command);

		if (command.substr(0, 10) == "push_front") {
			string str = command.substr(11);
			s.push_front(stoi(str));
		}
		if (command.substr(0, 9) == "push_back") {
			string str = command.substr(10);
			s.push_back(stoi(str));
		}
		if (command.substr(0, 9) == "pop_front") {
			if (s.empty()) cout << -1 << "\n";
			else { 
				cout << s.front() << "\n";
				s.pop_front(); }
		}
		if (command.substr(0, 8) == "pop_back") {
			if (s.empty()) cout << -1 << "\n";
			else { cout << s.back()<<"\n"; s.pop_back(); }
		}
		if (command == "front") {
			if (s.empty()) cout << -1 << "\n";
			else cout << s.front() << "\n";
		}
		if (command == "size") {
			cout << s.size() << "\n";
		}
		if (command == "empty") {
			cout << s.empty() << "\n";
		}
		if (command == "back") {
			if (s.empty()) cout << -1 << "\n";
			else {
				cout << s.back() << "\n";
			}
		}
		N--;
	}
}
