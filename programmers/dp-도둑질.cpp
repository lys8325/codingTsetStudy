#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <iostream>

using namespace std;

int memo[2][1000000];

int dp(vector<int> &money, int used, int pos){
    int &val = memo[used][pos];
    
    if(val != -1){
        return val;
    }
    
    val = max(dp(money, used, pos-2) + money[pos], dp(money, used, pos-1));
    return val;
}

int solution(vector<int> money) {
    int len = money.size();
    int answer = -1;
   
    for(int i=0;i<2;++i){
        memset(memo[i], -1, len*4);
    }
    
    memo[1][0] = money[0];
    memo[1][1] = max(money[0], money[1]);
    memo[0][0] = 0;
    memo[0][1] = money[1];
    
    return answer = max(dp(money, 1, len-2), dp(money, 0, len-1));
}
