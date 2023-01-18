#include <string>
#include <vector>
#include <queue>
using namespace std;
int answer = 0;
bool check[51];
int diff(string a,string b){
    int cnt = 0;
    for(int i = 0;i<a.length();i++){
        if(a[i] == b[i]) continue;
        cnt++;
    }
    return cnt;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue <pair<string,int>> q;
    q.push({begin,0});
    while(!q.empty()){
        string str = q.front().first;
        int count = q.front().second;
        q.pop();
        if(str == target){
            answer = count;
            break;
        }
        for(int i = 0;i<words.size();i++){
            string nstr = words[i];
            if(!check[i]){
                if(diff(str,nstr) == 1){
                    check[i] = true;
                    q.push({nstr,count+1});
                }
            }
        }
    }
    return answer;
}