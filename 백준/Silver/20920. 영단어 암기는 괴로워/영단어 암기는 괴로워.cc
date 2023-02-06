#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
map <string, int> m;
vector <pair<string, int>> v;
bool cmp(pair<string,int> A,pair<string,int> B) {
	if (A.second > B.second) return true;
	else if (A.second < B.second)return false;
	else if (A.second == B.second) {
		if (A.first.length() > B.first.length()) return true;
		else if (A.first.length() < B.first.length()) return false;
		else if (A.first.length() == B.first.length()) {
			if (A.first < B.first) return true;
			else return false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int idx = 0;
	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
		if (word.length() < M) continue;
		else {
			if (m.find(word) == m.end()) {
				m[word] = idx++;
				v.push_back({ word,1 });
			}
			else {
				v[m[word]].second++;
			}
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << "\n";
	}
}