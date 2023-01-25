#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    long answer = 0;
    long start = 1;
    long div = 2*w + 1;
    for(int i = 0;i<stations.size();i++){
        if(i == 0){
            if(stations[i] - w > 1){
                long res = stations[i] - w -1;
                long len = res - start + 1;
                if(len % div == 0){
                    answer += len/div;
                }else{
                    answer += (len/div) + 1;
                }
                
            }
        }else{
            long res = (stations[i]-w-1) - (stations[i-1] +  w);
            if(res > 0){
                if(res % div == 0){
                    answer += res/div;
                }else{
                    answer += (res/div) + 1;
                }
            }
        }
    }
    long last = stations[stations.size()-1] + w + 1;
    if(last <= n){
        long res = n-last+1;
        if(res % div == 0){
                answer += res/div;
        }else{
                answer += (res/div) + 1;
        }
    }
    return answer;
}