#include <vector>
#include <algorithm>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    int dp[201][201];
    for(int i = 0;i<201;i++){
        for(int j = 0;j<201;j++){
            dp[i][j] = 99999;
        }
    }
    vector <int> v[201];
    for(int i = 0;i<201;i++){
        v[i].clear();
    }
    for(auto e : edge_list){
        v[e[0]].push_back(e[1]);
        v[e[1]].push_back(e[0]);
    }
    dp[0][gps_log[0]]=0;
    for(int i = 1;i< k;i++){
        for(int c = 1; c<= n;c++){
            if(dp[i-1][c] == 99999) continue;
            for(int j = 0;j<v[c].size();j++){
                int nnode = v[c][j];
                int plus = 0;
                if(gps_log[i] != nnode){
                    plus++;
                }
                dp[i][nnode] = min(dp[i][nnode],dp[i-1][c] + plus);
            }
        }
    }
    if(dp[k-1][gps_log[k-1]] == 99999) return -1;
    answer = dp[k-1][gps_log[k-1]];
    return answer;
}