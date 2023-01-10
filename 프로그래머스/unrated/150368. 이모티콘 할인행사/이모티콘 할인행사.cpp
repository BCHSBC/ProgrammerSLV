#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int maxsum = 0;
int maxplus = 0;
void FUNC(vector<vector<int>> users,vector<int> emoticons,vector <int> v){
    if(v.size() == emoticons.size()){
        int sum = 0;
        int plus = 0;
        for(int i = 0;i<users.size();i++){
            int usersum = 0;
            for(int j = 0;j<v.size();j++){
                if(users[i][0] <= v[j]){
                    usersum += ((emoticons[j]/100) * (100-v[j]));
                }
            }
            if(usersum >= users[i][1]){
                plus++;
            }else{
                sum += usersum;
            }
        }
        if(maxplus < plus){
            maxplus = plus;
            maxsum = sum;
        }else if(maxplus == plus){
            maxsum = max(maxsum,sum);
        }
        
        return;
    }
    for(int i = 1;i<=4;i++){
        v.push_back(i*10);
        FUNC(users,emoticons,v);
        v.pop_back();
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector<int> v;
    FUNC(users,emoticons,v);
    answer.push_back(maxplus);
    answer.push_back(maxsum);
    return answer;
}