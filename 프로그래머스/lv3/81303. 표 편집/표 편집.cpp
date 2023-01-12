#include <string>
#include <vector>
#include <stack>
//#include <iostream>
using namespace std;
bool isExist[1000001];
int up[1000001];
int down[1000001];
stack <pair<int,pair<int,int>>> s;
int nextnode(int cur,int cnt,int target,int ver){
    if(cnt == target) return cur;
    if(ver == 0) return nextnode(down[cur],cnt+1,target,ver);
    return nextnode(up[cur],cnt+1,target,ver);
}
string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    up[0] = -1;
    down[n-1] = -1;
    for(int i = 0;i<n;i++){
        isExist[i] = true;
        if(i>0) up[i] = i-1;
        if(i<n-1) down[i] = i+1;
    }
    int nk,dcount,ucount,node,lastnode = n-1;
    pair<int,int> p;
    int count = 0;
    for(int i = 0;i<cmd.size();i++){
        string command = cmd[i];
        switch (command[0]){
            case 'D':
                dcount = stoi(command.substr(2));
                k = nextnode(k,0,dcount,0);
            break;
                
            case 'U':
                ucount = stoi(command.substr(2));
                k = nextnode(k,0,ucount,1);
            break;
                
            case 'C':  
                if(k == lastnode){
                    isExist[k] = false;
                    down[up[k]] = -1;
                    
                    s.push({k,{up[k],-1}});
                    
                    k = up[k];
                    lastnode = k;
                }else{
                    isExist[k] = false;
                    down[up[k]] = down[k];
                    up[down[k]] = up[k];
                
                    s.push({k,{up[k],down[k]}});
                    
                    k = down[k];
                }
            break;
                
            case 'Z':
                node = s.top().first;
                p = s.top().second;
                isExist[node] = true;
                if(p.second == -1){
                    lastnode = node;                 
                }else{
                    up[p.second] = node;
                }
                down[p.first] = node;
                s.pop();
            break;
        }
        /*
        string tmp ="";
        for(int i = 0;i<n;i++){
        if(isExist[i]) tmp += "O";
        else tmp += "X";
    }
        cout << tmp << " " << k << " " << lastnode << "\n";
        */
    }
    for(int i = 0;i<n;i++){
        if(isExist[i]) answer += "O";
        else answer += "X";
    }
    return answer;
}