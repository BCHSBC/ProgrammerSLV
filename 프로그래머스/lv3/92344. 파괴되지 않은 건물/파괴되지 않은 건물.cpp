#include <string>
#include <vector>
using namespace std;
int board[1001][1001];
int solution(vector<vector<int>> b, vector<vector<int>> skill) {
    int answer = 0;
    for(int i = 0;i<skill.size();i++){
        if(skill[i][0] == 1){
            board[skill[i][1]][skill[i][2]] += -skill[i][5];
            board[skill[i][1]][skill[i][4]+1] += skill[i][5];
            board[skill[i][3]+1][skill[i][2]] += skill[i][5];
            board[skill[i][3]+1][skill[i][4]+1] += -skill[i][5];
        }else{
            board[skill[i][1]][skill[i][2]] += skill[i][5];
            board[skill[i][1]][skill[i][4]+1] += -skill[i][5];
            board[skill[i][3]+1][skill[i][2]] += -skill[i][5];
            board[skill[i][3]+1][skill[i][4]+1] += skill[i][5];
        }
    }
    for(int i = 0;i<b.size();i++){
        for(int j = 1;j<b[i].size();j++){
            board[i][j] += board[i][j-1];
        }
    }
    for(int i = 0;i<b.size();i++){
        for(int j = 1;j<b[i].size();j++){
            board[j][i] += board[j-1][i];
        }
    }
    for(int i = 0;i<b.size();i++){
        for(int j = 0;j<b[i].size();j++){
            if(b[i][j]+board[i][j] > 0) answer++;
        }
    }
    return answer;
}