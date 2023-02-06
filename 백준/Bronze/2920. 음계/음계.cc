#include <iostream>
#include <vector>
using namespace std;

int main() {
	int aList[8] = { 1,2,3,4,5,6,7,8 };
	int bList[8] = { 8,7,6,5,4,3,2,1 };

	int List[8] = {};
	for (int i = 0; i < 8; i++) {
		cin >> List[i];
	}
	bool aEqual = true;
	bool bEqual = true;
	for (int i = 0; i < 8; i++) {
		if (aList[i] == List[i] && aEqual) {
			aEqual = true;
		}
		else {
			aEqual = false;
		}

		if (bList[i] == List[i] && bEqual) {
			bEqual = true;
		}
		else {
			bEqual = false;
		}

	}
	if (aEqual) {
		cout << "ascending";
	}
	else if (bEqual) {
		cout << "descending";
	}
	else {
		cout << "mixed";
	}
}