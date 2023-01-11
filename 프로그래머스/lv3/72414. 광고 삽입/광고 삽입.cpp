#include <string>
#include <vector>
using namespace std;
long long cnt[360000];
int timeT(string str){
    int hour = stoi(str.substr(0,2));
    int minute = stoi(str.substr(3,2));
    int second = stoi(str.substr(6,2));
    return hour*3600 + minute*60 + second;
}
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    long pt = timeT(play_time);
    long at = timeT(adv_time);
    for(long i = 0;i<logs.size();i++){
        long s = timeT(logs[i].substr(0,8));
        long e = timeT(logs[i].substr(9));
        cnt[s]++;
        cnt[e]--;
    }
    long long sum = 0;
    
    for(long i =1;i<=pt;i++){
        cnt[i] += cnt[i-1];
    }
    for(long i =1;i<=pt;i++){
        cnt[i] += cnt[i-1];
    }
    long long max_sum = sum;
    long long t = 0;
    for(long i = 0;i<=pt-at;i++){
        sum = cnt[i+at-1];
        if(i>0) sum -=cnt[i-1];
        if(max_sum < sum){
            max_sum = sum;
            t = i;
        }
    }
    
    long tmp = t;
    if(tmp/3600 < 10) answer += "0"+to_string(tmp/3600);
    else answer += to_string(tmp/3600);
    answer += ":";
    tmp %= 3600;
    if(tmp/60 < 10) answer += "0" +to_string(tmp/60);
    else answer += to_string(tmp/60);
    answer += ":";
    tmp %= 60;
    if(tmp < 10) answer +=  "0" +to_string(tmp);
    else answer+= to_string(tmp);
    return answer;
}