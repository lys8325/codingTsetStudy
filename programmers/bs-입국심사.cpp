#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer, totalTime, left, right, mid;
    int timesSize = times.size();
    long long cnt;
    
    sort(times.begin(), times.end());
    totalTime = (long long) n * times[timesSize-1];
    answer = totalTime;
    left = 1; right = totalTime;
    
    while(left <= right){
        mid = (left + right) / 2;
        
        cnt = 0;
        for(int idx=0;idx<timesSize;++idx){
            cnt += (mid / times[idx]);
        }
        
        if(cnt >= n){
            right = mid - 1;
            answer = min(answer, mid);
        }else{
            left = mid + 1;
        }
    }

    
    return answer;
}
