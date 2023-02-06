#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
vector <int> v;
map <string,bool> mp;
int n, m;
void Select(int cnt,int idx,string str) {
	if (cnt == 0) {
		if (mp.find(str) == mp.end()) {
			mp.insert({ str,true });
			cout << str << "\n";
		}
		return;
	}
	else {
		for (int i = idx; i < v.size(); i++) {
				Select(cnt - 1, i,str + to_string(v[i])+ " ");
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	Select(m,0,"");
}