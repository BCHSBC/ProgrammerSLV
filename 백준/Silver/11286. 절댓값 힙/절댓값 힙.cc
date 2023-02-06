#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;
	priority_queue <pair<int, int>> p;
	while (N--) {
		int number;
		cin >> number;

		if (number == 0) {
			if (p.empty()) cout << 0 << "\n";
			else {
				cout << p.top().first * p.top().second << "\n";
				p.pop();
			}
		}
		else {
			if (number > 0)
				p.push({ -1 * abs(number),-1 });
			else
				p.push({ number,1 });
		}
	}
}