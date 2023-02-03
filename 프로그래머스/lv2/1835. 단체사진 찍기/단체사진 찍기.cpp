#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
int ans;
bool visit[8];
char C[8];
bool POS(string str,vector<string>& data){
    for(int i = 0;i<data.size();i++){
            char operand1 = data[i][0];
            int operand1loc = str.find(operand1);
            char operand2 = data[i][2];
            int operand2loc = str.find(operand2);
            char op = data[i][3];
            int value = (data[i][4] - '0') + 1;
            
            if(op == '='){
                if(abs(operand1loc-operand2loc) != value) {return false;}
            }
            if(op == '>'){
                if(abs(operand1loc-operand2loc) <= value) {return false;}
            }
            if(op == '<'){
                if(abs(operand1loc-operand2loc) >= value) {return false;}
            }
        }
    return true;
}
void permutation(string str,vector<string>& data)
{
    if(str.length() == 8){
        if(POS(str,data)){
            ans++;
        }
    }else{
        for(int i = 0;i<8;i++){
            if(!visit[i]){
                visit[i] = true;
                permutation(str+C[i],data);
                visit[i] = false;
            }
        }
    }
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    ans = 0;
    string s = "ACFJMNRT";
    for(int i = 0;i<s.length();i++){
        C[i] = s[i];
    }
    for(auto v : visit){
        visit[v] = false;
    }
    permutation("",data);
    return ans;
}