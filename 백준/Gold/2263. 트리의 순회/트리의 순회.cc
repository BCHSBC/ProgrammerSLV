#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int inorder[100002];
int postorder[100002];
int idx[100002];
int root = 0;

void Preorder(int is, int ie, int ps, int pe) {
	if (is > ie || ps > pe) return;
	int root = postorder[pe];
	cout << root << " ";
	int p = idx[root];

	int left = p - is;
	Preorder(is, p - 1, ps, ps + left - 1);
	Preorder(p + 1, ie, ps + left, pe - 1);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> inorder[i];
		idx[inorder[i]] = i;

	}
	for (int i = 1; i <= n; i++) {
		cin >> postorder[i];
	}
	Preorder(1, n, 1, n);
	
}