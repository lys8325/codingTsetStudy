#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int solution(string str)
{
    int answer = 0;
    stack<char> s;
    queue<char> q;
    
    for(char c : str){
        q.push(c);
    }
    
    s.push(q.front());
    q.pop();
    
    while(!q.empty()){
        if(s.empty()){
            s.push(q.front());
            q.pop();
        }else{
            if(s.top() == q.front()){
                s.pop();
                q.pop();
            }else{
                s.push(q.front());
                q.pop();
            }
        }
    }
    
    if(s.empty()){
        answer = 1;
    }

    return answer;
}
