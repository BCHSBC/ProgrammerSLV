#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector <char> v[27];
void FIRST(char alpha) {
	cout << alpha;
	char left = v[alpha-'A'][0];
	char right = v[alpha-'A'][1];
	if (left != '.') FIRST(left);
	if (right != '.') FIRST(right);
}
void MID(char alpha) {
	char left = v[alpha - 'A'][0];
	char right = v[alpha - 'A'][1];
	if (left != '.') MID(left);
	cout << alpha;
	if (right != '.') MID(right);

}
void BACK(char alpha) {
	char left = v[alpha - 'A'][0];
	char right = v[alpha - 'A'][1];
	if (left != '.') BACK(left);
	if (right != '.') BACK(right);
	cout << alpha;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		v[a - 'A'].push_back(b);
		v[a - 'A'].push_back(c);
	}
	FIRST('A');
	cout << "\n";
	MID('A');
	cout << "\n";
	BACK('A');
}