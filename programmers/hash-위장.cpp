#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;
    int answer = 1;
    int clothesSize = clothes.size();
    
    for(int index=0;index<clothesSize;++index){
        m[clothes[index][1]]++;
    }
    
    for(auto iter : m){
        answer *= ((iter.second) + 1);
    }
    
    return answer-1;
}
