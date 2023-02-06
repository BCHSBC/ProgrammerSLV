#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
deque <int> SP(string str) {
	istringstream ss(str);
	string stringBuffer;
	deque<int> q;
	q.clear();
	while (getline(ss, stringBuffer, ',')) {
		q.push_back(stoi(stringBuffer));
	}
	return q;
}
int main() {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		string command;
		cin >> command;
		deque <int> dq;
		int len;
		cin >> len;
		string numberList;
		cin >> numberList;
		numberList = numberList.substr(1, numberList.length() - 2);
		dq = SP(numberList);
		bool direct = false;
		bool okay = false;
		for (int i = 0; i < command.length(); i++) {
			if (command[i] == 'R') direct = !direct;
			if (command[i] == 'D') {
				if (direct) {
					if (dq.empty()) {
						okay = true;
						break;
					}
					dq.pop_back();
				}
				else {
					if (dq.empty()) {
						okay = true;
						break;
					}
					dq.pop_front();
				}
			}
		}
		if (okay) cout << "error" << "\n";
		else {
			cout << "[";
			if (!direct) {
				while (!dq.empty()) {
					cout << dq.front();
					if (dq.size() != 1) {
						cout << ",";
					}
					dq.pop_front();
				}
			}
			else {
				while (!dq.empty()) {
					cout << dq.back();
					if (dq.size() != 1) {
						cout << ",";
					}
					dq.pop_back();
				}
			}
			cout << "]" << "\n";
		}
	}
}