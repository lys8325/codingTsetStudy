#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(string s) {
    int strLen = s.length();
    int answer = strLen;
    int num = 0;
    string copyStr = s;
    string temp;
    string tempResult;
    string target;
    queue<string> queue;
    int j;
    for(int i=1;i<=(strLen/2);++i){
        for(j=0;j<strLen/i;++j){
            temp = copyStr.substr(j*i,i);
            queue.push(temp);
        }
        if(j*i < strLen){
            temp=copyStr.substr(j*i);
            queue.push(temp);
        }
        
        target = queue.front();
        queue.pop();
        num = 1;
        while(!queue.empty()){
            if(target == queue.front()){
                ++num;
                target = queue.front();
            }else{
                if(num == 1){
                    tempResult += target;
                }else{
                    tempResult += (to_string(num) + target);
                }
                num=1;
                target = queue.front();
            }
            target = queue.front();
            queue.pop();
            if(queue.empty()){
                if(num == 1){
                    tempResult += target;
                }else{
                    tempResult += (to_string(num) + target);
                }
            }
        }
        if(answer > tempResult.length()){
            answer = tempResult.length();
        }
        tempResult.clear();
    }
    return answer;
}
