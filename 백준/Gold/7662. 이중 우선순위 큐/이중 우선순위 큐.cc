#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main() {
	int T;
	cin >> T;
	cin.ignore();
	while (T--) {
		ios_base::sync_with_stdio(false);
		int n;
		cin >> n;
		cin.ignore();
		multiset <int,less<int>> m;
		while (n--) {
			string str;
			getline(cin, str);
			if (str[0] == 'I') {
				m.insert(stoi(str.substr(2)));
			}
			if (str[0] == 'D') {
				if (str[2] == '1') {
					if (m.empty()) continue;
					multiset<int, greater<int>>::iterator iter;
					iter = m.end();
					iter--;
					m.erase(iter);
				}
				else {
					if (m.empty())continue;
					m.erase(m.begin());
				}
			}
		}
		if (m.empty()) cout << "EMPTY" << "\n";
		else {
			multiset<int, greater<int>>::iterator iter;
			iter = m.end();
			iter--;
			cout << *iter << " " << *m.begin() << "\n";
		}
	}
}