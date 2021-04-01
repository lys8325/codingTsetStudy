#include <string>
#include <vector>
#include <iostream>
using namespace std;

int memo[60001];

int dp(int n){
    int &v = memo[n];
    
    if(v != 0){
        return v;
    }
    
    v = dp(n-1) + dp(n-2);
    v %= 1000000007;
    
    return v;
}

int solution(int n) {
    memo[1] = 1;
    memo[2] = 2;
    
    int answer = dp(n);

    return answer;
}
