#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	stack <int> s;
	while (n--) {
		int number;
		cin >> number;
		if (!number) {
			s.pop();
		}
		else {
			s.push(number);
		}
	}
	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum;
}