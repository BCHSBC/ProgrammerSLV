#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
unordered_map<string, vector<string>> m;
unordered_map<string, int> IDX;
set<string> s;
bool check[10];
unordered_map<string, int> check2;

bool isFit(string a, string b) {
    if (a.length() != b.length()) return false;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i] && b[i] != '*')
            return false;
    }
    return true;
}

void SLV(int cnt, vector<string>& banned_id, vector<int> v) {
    if (cnt == banned_id.size()) {
        sort(v.begin(), v.end());
        string str = "";
        for (int i : v) str += to_string(i);
        s.insert(str);
        return;
    }
    for (string& id : m[banned_id[cnt]]) {
        int node = IDX[id];
        if (!check[node]) {
            check[node] = true;
            v.push_back(node);
            SLV(cnt + 1, banned_id, v);
            check[node] = false;
            v.pop_back();
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    for (int i = 0; i < user_id.size(); i++) IDX[user_id[i]] = i;
    for (string& id : banned_id) {
        if (!check2[id]) {
            check2[id] = 1;
            for (string& uid : user_id) {
                if (isFit(uid, id)) m[id].push_back(uid);
            }
        }
    }
    vector<int> v;
    SLV(0, banned_id, v);
    return s.size();
}
