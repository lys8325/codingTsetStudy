#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue<int> pq;
    queue<int> q;
    int len = priorities.size() - 1;
    int answer = 1;
    
    for(int n : priorities){
        q.push(n);
        pq.push(n);
    }
    
    while(1){
        if(q.front() == pq.top()){
            q.pop();
            pq.pop();
            
            if(location == 0){
                break;
            }else{
                --location;
            }
            
            ++answer;
            --len;
        }else{
            q.push(q.front());
            q.pop();
            
            if(location == 0){
                location = len;
            }else{
                --location;
            }
        }
    }
    
    
    return answer;
}
