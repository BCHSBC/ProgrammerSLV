#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string str;
	int num;
	cin >> num;
	cin >> str;
	string b = "";
	string r = "";
	int lastr = 0, lastb = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'R') {
			r += 'R';
		}
		else {
			b += 'B';
		}
	}
	string bb = b + r;
	string rr = r + b;
	int bcount = 0;
	int rcount = 0;
	//cout << lastr << " " << lastb << "\n";
	for (int i = str.length()-1;i>=0; i--) {
		if (str[i] == 'R') continue;
		if (str[i] == 'B') {
			lastr = i + 1;
			break;
		}
	}
	for (int i = str.length()-1; i >= 0; i--) {
		if (str[i] == 'B') continue;
		if (str[i] == 'R') {
			lastb = i + 1;
			break;
		}
	}
	bcount = b.length() - (str.length() - lastb);
	rcount = r.length() - (str.length() - lastr);
	//cout << bcount << " " << rcount << "\n";
	cout << min(bcount, rcount);
}