#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int testCase;
	cin >> testCase;
	while (testCase--) {
		int n;
		cin >> n;
		map <string, int> m;
		for (int i = 0; i < n; i++) {
			string str1, str2;
			cin >> str1 >> str2;
			// 카테코리가 존재 할 경우
			if (m.find(str2) != m.end()) {
				m[str2]++;
			}
			else {
				m[str2] = 1;
			}
		}
		int allCase = 0;
		// 카테고리가 2개 이상이라서 조합이 가능한 경우
		if (m.size() >= 2) {
			allCase = 1;
			for (auto iter = m.begin(); iter != m.end(); iter++) {
				allCase *= ((iter->second)+1);
			}
			allCase -= 1;
			allCase -= n;
		}
		allCase += n;
		cout << allCase << "\n";
	}
}