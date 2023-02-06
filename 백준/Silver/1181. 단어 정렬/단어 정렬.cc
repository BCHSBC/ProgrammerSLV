#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	if (a.length() > b.length()) {
		return false;
	}
	else if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return true;
	}
}
int main() {
	int N;
	cin >> N;
	vector <string> v;
	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
		v.push_back(word);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		if (i > 0) {
			if (v[i] == v[i - 1]) {
				continue;
			}
		}
		cout << v[i] << "\n";
	}

}