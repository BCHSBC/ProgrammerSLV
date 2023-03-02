#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct Room{
    char type;
    int money;
    vector <int> jump;
};
bool check[1001];
vector <Room> v;
int N;
bool finish = false;
void SLV(int idx,int money){
    if(idx == N-1){
        finish = true;
        return;
    }
    Room r = v[idx];
    if(r.type == 'E' || r.type == 'T'){
        for(int i = 0;i<r.jump.size();i++){
            Room next = v[r.jump[i]-1];
            if(check[r.jump[i]-1]) continue;
            if(next.type == 'T'){
                if(money >= next.money){
                    check[r.jump[i]-1] = true;
                    SLV(r.jump[i]-1,money-next.money);
                    check[r.jump[i]-1] = false;
                }
            }else{
                check[r.jump[i]-1] = true;
                SLV(r.jump[i]-1,money);
                check[r.jump[i]-1] = false;
            }
        }
    }else if(r.type == 'L'){
        int newmoney = max(money,r.money);
        for(int i = 0;i<r.jump.size();i++){
            Room next = v[r.jump[i]-1];
            if(check[r.jump[i]-1]) continue;
            if(next.type == 'T'){
                if(newmoney >= next.money){
                    check[r.jump[i]-1] = true;
                    SLV(r.jump[i]-1,newmoney-next.money);
                    check[r.jump[i]-1] = false;
                }
            }else{
                check[r.jump[i]-1] = true;
                SLV(r.jump[i]-1,newmoney);
                check[r.jump[i]-1] = false;
            }
        }
    }
    if(finish) return;
}
int main(){
    while(true){
        cin >> N;
        v.clear();
        if(N == 0) break;
        for(int i = 0;i<N;i++){
            int cnt = 0;
            Room r;
            r.type ='a'; r.money=0; r.jump.clear();
            while(true){
            bool out = false;
            if(cnt == 0){
                cin >> r.type;
            }else if(cnt == 1){
                cin >> r.money;
            }else{
                while(true){
                    int number;
                    cin >> number;
                    if(number == 0) {
                        out = true;
                        break;
                    }
                    r.jump.push_back(number);
                }
                v.push_back(r);
            }
            if(out) break;
            cnt++;
            }
        }
        finish = false;
        SLV(0,0);
        if(finish) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
}