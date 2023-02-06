#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool list[21];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int T;
	cin >> T;
	cin.ignore();
	while (T--) {
		string str;
		getline(cin, str);
		if (str[0] == 'a' && str[1] == 'd') {
			list[stoi(str.substr(4))] = true;
		}
		if (str[0] == 'r') {
			list[stoi(str.substr(7))] = false;
		}
		if (str[0] == 'c') {
			if (list[stoi(str.substr(6))]) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		if (str[0] == 't') {
			list[stoi(str.substr(7))] = !list[stoi(str.substr(7))];
		}
		if (str[0] == 'a' && str[1] == 'l') {
			for (int i = 1; i <= 20; i++) {
				list[i] = true;
			}
		}
		if (str[0] == 'e') {
			for (int i = 1; i <= 20; i++) {
				list[i] = false;
			}
		}
	}
}