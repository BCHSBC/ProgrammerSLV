#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	while (1) {
		cin >> str;
		if (str == "0") break;
		bool OK = true;
		for (int i = str.length() / 2 - 1; i >= 0; i--) {
			if (str[i] == str[str.length() - (i + 1)]) {
				OK = true;
			}
			else {
				OK = false;
				break;
			}
		}
		if (OK) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}
}