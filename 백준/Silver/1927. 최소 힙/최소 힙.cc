#include <iostream>
#include <algorithm>
using namespace std;
int list[100001];
int last = 1;
void Change(int number,int location) {
	int leftNode = location * 2;
	int rightNode = location * 2 + 1;
	if (leftNode > last) return;
	if ((list[rightNode]==0 || list[leftNode] <= list[rightNode]) && list[leftNode] < number) {
		list[location] = list[leftNode];

		list[leftNode] = number;
		Change(number, leftNode);
	}
	else if (list[rightNode] && list[leftNode] > list[rightNode] && list[rightNode] < number) {
		list[location] = list[rightNode];
			list[rightNode] = number;
		Change(number, rightNode);
	}
}
void pop_front() {
	list[1] = list[last];
	//cout << list[last];
	list[last] = 0;
	last--;
	Change(list[1], 1);
}
void push(int number,int location) {
	int parent = list[location / 2];
	list[location] = number;
	if (location / 2 == 0) {
		return;
	}
	if (parent > number || parent == 0) {
		int tmp = number;
		list[location] = parent;
		list[location / 2] = number;
		push(number, location / 2);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		int number;
		cin >> number;
		if (!number) {
			cout << list[1] << "\n";
			if (list[1]) {
			pop_front();
		}
		}
		else {
			if (last == 1 && list[1] == 0) {
				list[1] = number;
			}
			else {
				push(number, last + 1);
				last++;
			}
		}
	}
}