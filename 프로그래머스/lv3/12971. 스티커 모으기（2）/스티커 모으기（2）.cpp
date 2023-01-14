#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[100001];
int dp2[100001];
int solution(vector<int> sticker)
{
    int answer =0;
    for(int i = 0;i<sticker.size()-1;i++){
        if(i==0) 
            dp[i] = sticker[0];
        if(i== 1)
            dp[i] = max(sticker[i],dp[0]);
        if(i>=2)
            dp[i] = max(dp[i-1],dp[i-2]+sticker[i]);
    }

    for(int i = 1;i<sticker.size();i++){
        if(i== 1)
            dp2[1] = sticker[1];
        if(i == 2)
            dp2[2] = max(dp2[1],sticker[2]);
        if(i>=3)
            dp2[i] = max(dp2[i-1],dp2[i-2]+sticker[i]);
    }
    if(sticker.size() >= 2)
        answer = max(dp2[sticker.size()-1],dp[sticker.size()-2]);
    else
        answer = sticker[0];
    return answer;
}