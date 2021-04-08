#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

bool check(int a, int b){
    return a < b;
}

int solution(vector<int> A, vector<int> B) {
    deque<int> a, b;
    int len = A.size();
    int answer = 0, numA, numB;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    for(int i=0;i<len;++i){
        a.push_back(A[i]);
        b.push_back(B[i]);
    }
    
    while(!a.empty()){
        if(a.back() >= b.back()){
            numA = a.back();
            numB = b.front();
            
            if(check(numA, numB)){
                ++answer;
            }
            
            a.pop_back();
            b.pop_front();
        }else{
            numA = a.back();
            numB = b.back();
            
            if(check(numA, numB)){
                ++answer;
            }
            
            a.pop_back();
            b.pop_back();
        }
    }
    
    return answer;
}
