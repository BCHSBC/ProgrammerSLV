#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m,p;
bool truth[51];
bool visit[51];
vector <vector<int>> party;
vector <int> personParty[51];
bool lie[51];
void check(int x) {
	for (int i = 0; i < personParty[x].size(); i++) {
		int theParty = personParty[x][i];
		
		for (int j = 0; j < party[theParty].size(); j++) {
			int thePerson = party[theParty][j];
			if (truth[thePerson]) {
				lie[theParty] = true;

				for (int q = 0; q < party[theParty].size(); q++) {
					int tP = party[theParty][q];
					if (tP == x) continue;
					if (visit[tP]) continue;
					visit[tP] = true;
					truth[tP] = true;
					check(tP);
				}
			}

		}

	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> p;
	for (int i = 0; i < p; i++) {
		int person;
		cin >> person;
		truth[person] = true;
	}
	for (int i = 0; i < m; i++) {
		int howmany;
		cin >> howmany;
		vector <int> v;
		for (int j = 0; j < howmany; j++) {
			int a;
			cin >> a;
			v.push_back(a);
			personParty[a].push_back(i); // 특정 사람이 무슨 파티에 속해있는지
		}
		party.push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			check(i);
		}
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		if (!lie[i]) cnt++;
	}
	cout << cnt;
}