#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    deque<int> dq;
    int answer = 0;
    
    sort(people.begin(), people.end());
    for(int i : people){
        dq.push_back(i);
    }
    
    while(!dq.empty()){
        if(dq.size() == 1){
            dq.pop_back();
        }else{
            if(dq.front() + dq.back() <= limit){
                dq.pop_back();
                dq.pop_front();
            }else{
                dq.pop_back();
            }
        }
        
        ++answer;
    }
    
    return answer;
}
