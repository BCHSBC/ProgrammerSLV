#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	queue <int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	int counter = 0;
	cout << "<";
	while (!q.empty()) {
		if (counter == k-1) {
			cout << q.front();
			q.pop();
			counter = 0;
			if (!q.empty()) cout << ", ";
		}
		else {
			q.push(q.front());
			q.pop();
			counter++;
		}
	}
	cout << ">";
}