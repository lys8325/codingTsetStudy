#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <iostream>
using namespace std;

int memo[101][101];
bool isPuddle[101][101];

int dp(int y, int x){
    if(y < 1 || x < 1){
        return 0;
    }
    
    int &val = memo[y][x];
    
    if(val != -1){
        return val;
    }
    
    val = 0;
    val += dp(y-1, x);
    val += dp(y, x-1);
    val %= 1000000007;
    
    return val;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int puddlesSize = puddles.size();
    
    for(int  index=1;index<=m;++index){
        memset(memo[index], -1, (n+1)*4);
    }
    
    for(int index=0;index<puddlesSize;++index){
        isPuddle[puddles[index][0]][puddles[index][1]] = true;
        memo[puddles[index][0]][puddles[index][1]] = 0;
    }
    
    memo[1][1] = 1;
    answer = dp(m, n);    
    return answer;
}
