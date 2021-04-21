#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> sum;
int maxSum = -1;

void getCombi(int n, int idx, int cnt, vector<int> &nums, vector<int> &combi){
    if(cnt == 3){
        int tmp = combi[0] + combi[1] + combi[2];
        sum.push_back(tmp);
        
        maxSum = max(maxSum, tmp);
        
        return;
    }
    
    for(int i=idx;i<n;++i){
        combi.push_back(nums[i]);
        getCombi(n, i+1, cnt+1, nums, combi);
        combi.pop_back();
    }
}

int solution(vector<int> nums) {
    int answer = 0;
    vector<int> combi;
    getCombi(nums.size(), 0, 0, nums, combi);

    bool isPrime[maxSum+1];
    for(int i=2;i<=maxSum;++i){
        isPrime[i] = true;
    }
    
    for(int i=2;i*i<=maxSum;++i){
        if(isPrime[i]){
            for(int j=i*i;j<=maxSum;j += i){
                isPrime[j] = false;
            }
        }
    }
    
    for(int i : sum){
        if(isPrime[i]){
            ++answer;
        }
    }
    
    return answer;
}
