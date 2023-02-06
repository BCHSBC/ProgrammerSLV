#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int L[101];
bool V[101];
bool VV[101];
vector <int> ans;
vector <int> tmp;
int max_count = 0;
void DFS(int node,int idx) {
	V[idx] = true;
	if (node == L[idx]) {
		for (int i = 1; i <= n; i++) {
			if (V[i]) {
				VV[i] = true;
			}
		}
		V[idx] = false;
		return;
	}
	if (!V[L[idx]]) {
		DFS(node,L[idx]);
	}
	V[idx] = false;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> L[i];
	}
	for (int i = 1; i <= n; i++) {
		if(!VV[i])
			DFS(i,i);
	}
	for (int i = 1; i <= n; i++) {
		if (VV[i]) ans.push_back(i);
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}