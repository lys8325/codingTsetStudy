#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int memo[2][100000];

int dp(vector<int> &sticker, int idx, int isFirst){
    int &v = memo[isFirst][idx];
    
    if(v != -1){
        return v;
    }
    
    v = max(dp(sticker, idx-2, isFirst)+sticker[idx], dp(sticker, idx-1, isFirst));
    
    return v;
}

int solution(vector<int> sticker)
{
    int answer = 0;
    int len = sticker.size();
    
    if(len == 1){
        answer = sticker[0];
        return answer;
    }
    
    memset(memo[0], -1, 4*len);
    memset(memo[1], -1, 4*len);
    memo[1][0] = sticker[0];
    memo[1][1] = sticker[0];
    memo[0][0] = 0;
    memo[0][1] = sticker[1];
    
    answer = max(dp(sticker, len-1, 0), dp(sticker, len-2, 1));

    return answer;
}
