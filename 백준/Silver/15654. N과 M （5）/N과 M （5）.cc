#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<int> v;
bool check[9];
int n, m;
vector <int> vv;
void SLV(int m) {
	if (m == 0) {
		for (int i = 0; i < vv.size(); i++) {
			if (i == vv.size() - 1) {
				cout << vv[i] << "\n";
			}
			else {
				cout << vv[i] << " ";
			}
		}
		return;
	}
	for(int i =0;i<n;i++){
		if (!check[i]) {
				check[i] = true;
				vv.push_back(v[i]);
				SLV(m - 1);
				check[i] = false;
				vv.pop_back();
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		v.push_back(number);
	}
	sort(v.begin(), v.end());
	SLV(m);
}