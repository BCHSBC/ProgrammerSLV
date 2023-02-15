#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int T;
int n;
vector <int> pre;
vector <int> in;
void post(int s,int e,int pos){
    for(int i = s;i< e;i++){
        if(in[i] == pre[pos]){
            post(s,i,pos+1);
            post(i+1,e,pos+1+i-s);
            cout << pre[pos] << " ";
        }
    }
}
void SLV(){
    int root = 0;
    post(root,n,0);
}
int main(){
    cin >> T;
    while(T--){
        cin >> n;
        int a;
        pre.clear();
        in.clear();
        for(int i = 0;i<n;i++){
            cin >> a;
            pre.push_back(a);
        }
        for(int i = 0;i<n;i++){
            cin >> a;
            in.push_back(a);
        }
        SLV();
        cout << "\n";
    }
    
}