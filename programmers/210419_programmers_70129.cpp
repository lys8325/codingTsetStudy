#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string lenToBinary(int len){
    string ret;
    while(len != 0){
        ret.push_back(len % 2 + '0');
        len /= 2;
    }
    
    reverse(ret.begin(), ret.end());
    return ret;
}

string removeZero(string s){
    string ret;
    for(char c : s){
        if(c == '1'){
            ret.push_back(c);
        }
    }
    
    return ret;
}

vector<int> solution(string s) {
    vector<int> answer;
    string ret;
    int cntR = 0, cntZ = 0;
    int prevLen, curLen;
    
    while(s != "1"){
        prevLen = s.size();
        s = removeZero(s);
        curLen = s.size();
        
        s = lenToBinary(curLen);
        ++cntR;
        cntZ += prevLen - curLen;
    }
    
    answer.push_back(cntR);
    answer.push_back(cntZ);
    return answer;
}
