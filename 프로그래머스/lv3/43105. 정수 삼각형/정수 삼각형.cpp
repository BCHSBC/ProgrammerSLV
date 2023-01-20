#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int tri[501][501];
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for(int i = 0;i<triangle[triangle.size()-1].size();i++){
        tri[triangle.size()-1][i] = triangle[triangle.size()-1][i];
    }
    for(int i = triangle.size()-2;i>=0;i--){
        for(int j = 0;j<triangle[i].size();j++){
            tri[i][j] = max(tri[i+1][j],tri[i+1][j+1]) + triangle[i][j];
        }
    }
    answer = tri[0][0];
    return answer;
}