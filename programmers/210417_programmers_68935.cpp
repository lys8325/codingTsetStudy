#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    string str = "";
    
    while(n != 0){
        str.append(to_string(n%3));
        n /= 3;
    }

    int len = str.length();    
    for(int i=0;i<len;++i){
        answer += (str[i]-'0') * pow(3,len-1-i);
    }
    
    return answer;
}
