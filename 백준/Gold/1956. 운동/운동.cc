#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 987654321
int V,E;
vector <pair<int,int>> adj[401];
int dist[401][401];
int main(){
    cin >> V >> E;
    for(int i = 1;i<=V;i++){
        for(int j =1;j<=V;j++){
            dist[i][j] = INF;
        }
    }
    for(int i = 0;i<E;i++){
        int s,e,d;
        cin >> s >> e >> d;
        dist[s][e] = d;
    }
    for(int i = 1;i<=V;i++){
        for(int j =1;j<=V;j++){
            for(int k = 1;k<=V;k++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    int minDist = INF;
    for(int i =1;i<=V;i++){
        minDist = min(minDist,dist[i][i]);
    }
    if(minDist==INF) cout << -1;
    else cout << minDist;
}
