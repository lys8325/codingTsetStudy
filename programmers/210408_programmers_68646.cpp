#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> a) {
    int answer = 1;
    int aLen = a.size();
    int left = 0, right = aLen-1;
    int leftMin = a[left], rightMin = a[right];
    
    while(left < right){
        if(leftMin < rightMin){
            --right;
            if(rightMin > a[right]){
                ++answer;
                rightMin = a[right];
            }
        }else{
            ++left;
            if(leftMin > a[left]){
                ++answer;
                leftMin = a[left];
            }
        }
    }

    return answer;
}
