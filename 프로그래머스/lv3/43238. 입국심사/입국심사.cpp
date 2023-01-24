#include <string>
#include <vector>
#include <limits>
using namespace std;

long long solution(int n, vector<int> times) {
    unsigned long long answer = 18446744073709551615;
    unsigned long long start = 0;
    while(start + 1 < answer){
        unsigned long long mid = (answer +start)/2;
        unsigned long long sum = 0;
        for(int i = 0;i<times.size();i++){
            sum += mid/times[i];
        }
        if(sum >= n){
            answer = mid;
        }else{
            start = mid;
        }
        
    }
    return answer;
}