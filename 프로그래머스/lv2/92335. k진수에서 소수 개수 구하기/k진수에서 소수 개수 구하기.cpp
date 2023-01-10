#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;
bool isPrime(long long number){
    if(number == 0 || number == 1) return false;
    for(int i = 2;i<= sqrt(number);i++){
        if(number % i == 0) return false;
    }
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    string number = "";
    while(n > 0){
        int remainder = n % k;
        number = to_string(remainder) + number;
        n = n / k;
    }
    string str = "";
    for(int i = 0;i<number.length();i++){
        if(number[i] == '0'){
            if(str != "" && isPrime(stoll(str))) answer++;
            str = "";
        }else{
            str += number[i];
        }
    }
    if(str != ""){
        if(isPrime(stoll(str))) answer++;
    }
    return answer;
}