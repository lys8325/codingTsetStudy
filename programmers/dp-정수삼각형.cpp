#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int memo[500][500];

int dp(int y, int x, vector<vector<int>> &triangle){
    if(y < 0 || x < 0){
        return -1;
    }
    
    int &val = memo[y][x];
    
    if(val != -1){
        return val;
    }
    
    val = max(dp(y-1, x-1, triangle), dp(y-1, x, triangle)) + triangle[y][x];
    return val;
}

int solution(vector<vector<int>> triangle) {
    int answer = -1;
    int height = triangle.size();
    
    for(int index=0;index<height;++index){
        memset(memo[index], -1, (index+1)*4);
    }
    
    memo[0][0] = triangle[0][0];
    for(int index=0;index<height;++index){
        answer = max(answer, dp(height-1, index, triangle));
    }
    
    return answer;
}
