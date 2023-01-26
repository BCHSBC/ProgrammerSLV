#include <string>
#include <iostream>
using namespace std;
bool check[26];
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
bool isCorrect(string str,int mode){
    for(int i = 0;i<str.length();i++){
        if((str[i] >= 'A' && str[i] <= 'Z') || (mode == 1 && str[i] == ' ')) continue;
        return false;
    }
    return true;
}
bool isBig(char c){
    return (c >= 'A' && c <= 'Z'); 
}
string SLV(string str,int mode){
    //cout << str << "\n";
    if(isCorrect(str,0)){
        return str;
    }
    string res = "";
    int s = 0;
    int e = 0;
    int cnt = 0;
    //1. 소문자의 위치를 먼저 찾자
    for(int i = 0;i<str.length();i++){
        if(!isBig(str[i])){
            s = i;
            break;
        }
    }
    for(int i = s;i<str.length();i++){
        if(str[i] == str[s]){
            e = i;
            cnt++;
        }
    }
    if(check[str[s]-'a']) return "false";
    check[str[s]-'a']= true;
    if(e == s){ // 한번 나오면 규칙 1
        if(s == 0 || s+1 >= str.length()) return "false";
        string first = "";
        if(s - 1> 0){
            first = str.substr(0,s-1);
            first += " ";
        }
        res += first;
        res += str[s-1];
        res += str[s+1];
        string second="";
        if(s + 2 < str.length()){
            res += " ";
            second = str.substr(s+2);
            res += SLV(second,-1);
        }
        return res;
    }else if(cnt == 2) {// 두번 규칙 2
        if(mode != 1){
            if(e - 2 < s) return "false";
            string first = "";
            if(s> 0){
                first = str.substr(0,s);
                first += " ";
            }
            res += first;
            string tmp = "";
            for(int i = s+1;i<= e-1;i++){
                tmp += str[i];
            }
            res += SLV(tmp,1);
            string second="";
            if(e + 1 < str.length()){
                res += " ";
                second = str.substr(e+1);
                res += SLV(second,-1);
            }
            return res;
        }else{
            if(s == 0 || e == str.length()-1) return "false";
        string first = "";
        if(s - 1 > 0){
            first = str.substr(0,s-1);
            first += " ";
        }
        res += first;
        for(int i = s-1;i<=e+1;i+=2){
            res += str[i];
            if(i<e+1 && str[i+1] != str[s]) return "false";
        }
        string second="";
        if(e + 2 < str.length()){
            res += " ";
            second = str.substr(e+2);
            res += SLV(second,-1);
        }
        return res;
        }
    }else if(cnt >= 3){ // 3번 이상 나오면 규칙 1
        if(s == 0 || e == str.length()-1) return "false";
        string first = "";
        if(s - 1 > 0){
            first = str.substr(0,s-1);
            first += " ";
        }
        res += first;
        for(int i = s-1;i<=e+1;i+=2){
            res += str[i];
            if(i<e+1 && str[i+1] != str[s]) return "false";
        }
        string second="";
        if(e + 2 < str.length()){
            res += " ";
            second = str.substr(e+2);
            res += SLV(second,-1);
        }
        return res;
    }
    return "false";
}
string solution(string sentence) {
    string answer = "";
    for(int i = 0;i<sentence.length();i++){
        if(sentence[i] == ' ')
            return "invalid";
    }
    for(int i = 0;i<26;i++){
        check[i] = false;
    }
    answer = SLV(sentence,-1);
    //cout << answer;
    if(isCorrect(answer,1))
        return answer;
    return "invalid";
}