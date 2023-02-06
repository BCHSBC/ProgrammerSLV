#include <iostream>
#include <vector>
using namespace std;
bool check[7];
vector <int> v;
void solve(int n, int m, int cnt,int start) {
	if (cnt == m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = start; i <= n; i++) {
				v.push_back(i);
				solve(n, m, cnt + 1,i);
				v.pop_back();
			}
		}
	}

int main() {
	int n, m;
	cin >> n >> m;
	solve(n,m,0,1);
}