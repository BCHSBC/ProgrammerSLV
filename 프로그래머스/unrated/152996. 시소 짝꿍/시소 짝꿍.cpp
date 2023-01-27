#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool is[4001][4001];
long long solution(vector<int> weights) {
    long long answer = 0;
    for(int i = 100;i<=1000;i++){
        for(int x = 2;x<=4;x++){
            for(int y = 2;y<=4;y++){
                int n= i*x;
                if(n% y == 0){
                    is[i][n/y] = true;
                }
            }
        }
    }
    for(int i = 0;i<weights.size();i++){
        for(int j = i+1;j<weights.size();j++){
            if(is[weights[i]][weights[j]]) 
                answer++;
        }
    }
    return answer;
}