#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int cnt[5000001];
int qwe[5000001];
vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    vector<int> cnt(e + 1);
    for (int i = 1; i <= e; i++)
    {
        for (int j = 1; j <= e / i; j++)
        {
            cnt[i * j]++;
        }
    }
    int maxidx=0;
    int maxsum = 0;
    for(int i = e;i>=1;i--){
        if(maxsum <= cnt[i]){
            maxsum = cnt[i];
            maxidx = i;
        }
        qwe[i] = maxidx;
    }
    for(int i = 0;i<starts.size();i++){
        answer.push_back(qwe[starts[i]]);
    }
    return answer;
}