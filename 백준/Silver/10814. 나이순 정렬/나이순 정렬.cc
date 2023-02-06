#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

bool cmp(tuple <int, int, string> a, tuple <int, int, string> b) {
	if (get<1>(a) > get<1>(b)) {
		return false;
	}
	else if (get<1>(a) == get<1>(b)) {
		return get<0>(a) < get<0>(b);
	}
	else {
		return true;
	}
}
int main() {
	int N;
	cin >> N;
	vector<tuple <int, int, string>> v;
	for (int i = 0; i < N; i++) {
		int age;
		string name;
		cin >> age >> name;
		v.push_back({ i,age,name });
	}
	sort(v.begin(), v.end(),cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << get<1>(v[i]) << " " << get<2>(v[i]) << "\n";
	}
}