#include <string>
#include <vector>
#include <math.h>
//#include <iostream>
using namespace std;
bool SLV(string num){
    if(num.length() == 1) return true;
    int midx = num.length()/2;
    string check = "";
    for(int i = 0;i<num.length();i++) check += "0";
    if(num[midx] != '1') {
        if(num == check) return true;
        else return false;
    }
    bool res = true;
    res = res &&  SLV(num.substr(0,midx));
    res = res &&  SLV(num.substr(midx+1));
    
    return res;
}
string toBin(long long n){
    string res="";
    while(n > 0 ){
        if(n % 2 == 0) res = "0" + res;
        else res = "1" + res;
        n /= 2;
    }
    //cout << res << "\n";
    return res;
}
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(int i = 0;i < numbers.size();i++){
        long long num = numbers[i];
        string input = toBin(num);
        int c = 1;
        int prev = 0;
        while(true){
            int llen = prev + pow(2,(c-1));
            if(llen >= input.length()) {
                prev = llen;
                break;
            }
            prev = llen;
            c++;
        }
        while(prev > input.length()){
            input = "0" + input;
        }
        //cout << input << "\n";
        bool res = SLV(input);
        if(res) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}