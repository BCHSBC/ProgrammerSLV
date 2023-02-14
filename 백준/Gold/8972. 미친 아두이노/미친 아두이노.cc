#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int R,C;
string input;
vector <pair<int,int>> ca;
pair<int,int> sl;
int dx[10] = {0,1,1,1,0,0,0,-1,-1,-1};
int dy[10] = {0,-1,0,1,-1,0,1,-1,0,1};
int L[102][102];
int AD[102][102];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> R >> C;
    for(int i = 0;i<R;i++){
        string str;
        cin >> str;
        for(int j = 0;j<str.length();j++){
            if(str[j] == 'I') {
                sl = {i,j};
                L[i][j] = 1;
            }
            else if(str[j] == 'R') {
                ca.push_back({i,j});
                AD[i][j]++;
                //isOne[ca.size()-1] = true;
            }
        }
    }
    cin >> input;
    int isDone = 0;
    for(int i = 0;i<input.length();i++){
        int x = input[i]-'0';
        // 1. 종수가 아두이노를 8가지 방향으로 이동시키거나 그 위치에 그대로 둔다
        L[sl.first][sl.second] = 0;
        sl = {sl.first+dx[x],sl.second+dy[x]};
        // 2. 종수의 아두이노가 미친 아두이노가 있는 칸으로 이동한 경우 게임이 끝난다
        if(AD[sl.first][sl.second] > 0){
            isDone = i+1;
            break;
        }
        L[sl.first][sl.second] = 1;
        
        // 3. 미친 이두이노는 8가지 방향중 종수의 아두이노와 가장 가까워지는 방향으로 이동한다
        for(int j = 0;j < ca.size();j++){
            // ***
            // 이동방향 8가지 for 문으로 돌리다가 시간 초과나서 바꿈
            // **
            pair<int,int> newCa = ca[j];
            if(newCa.first > sl.first){
                newCa.first -= 1;
            }else if(newCa.first < sl.first){
                newCa.first += 1;
            }
            if(newCa.second > sl.second){
                newCa.second -= 1;
            }else if(newCa.second < sl.second){
                newCa.second += 1;
            }
            // 미친 아두니오가 종수 있는 칸으로 이동하면 게임이 끝나게 된다
            if(newCa == sl){
                isDone = i+1;
                break;
            }
            AD[ca[j].first][ca[j].second]--;
            ca[j] = newCa;
            AD[ca[j].first][ca[j].second]++;
        }
        if(isDone != 0) break;
        
        // 2개 또는 그 이상의 미친 아두이노가 같은 칸에 있으면 폭발한다
        // 아두이노가 터졌는지 안터졌는지를 bool형 배열로 선언하여
        // 관리하다가 시간초과 떠서 그냥 해당 아두이노를 아에 삭제하는거로 변경
        // 아예 삭제할 때 이중 포문 써서 삭제하다가 시간초과나서
        // 개수를 저장하는 배열 따로 정의해서 사용
        for(int i = 0;i<R;i++){
            for(int j=0;j<C;j++){
                if(AD[i][j] > 1){
                    AD[i][j] = 0;
                    for(int k = 0;k<ca.size();k++){
                        if(ca[k].first == i && ca[k].second == j){
                            ca.erase(ca.begin()+k);
                            k--;
                        }
                    }
                }
            }
        }
    }
    
    if(isDone != 0){
        cout << "kraj " << isDone;
    }else{
        L[sl.first][sl.second] = 1;
        for(int i = 0;i<ca.size();i++){
            L[ca[i].first][ca[i].second] = 2;
        }
        for(int i = 0;i<R;i++){
            for(int j = 0;j<C;j++){
                if(AD[i][j]) cout << 'R';
                else if(L[i][j] == 0) cout << '.';
                else if(L[i][j] == 1) cout << 'I';
            }
            cout << "\n";
        }
    }
}