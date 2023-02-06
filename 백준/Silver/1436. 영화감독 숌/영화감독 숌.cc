#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int cnt = 0;
    int num = 666;
    while(cnt < n){
        string str = to_string(num);
        bool flag = false;
        int cnt6=0;
        for(int i = 0;i<str.length();i++){
            if(!flag && str[i] == '6'){
                flag = true;
                cnt6++;
            } else if(flag && str[i] == '6'){
                if(cnt6== 2){
                    cnt++;
                    break;
                }else {
                    cnt6++;
                }
            }else{
                flag = false;
                cnt6=0;
            }
        }
        num++;
    }
    cout << num-1;
}