#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(int a, int b){
    string str1 = to_string(a);
    string str2 = to_string(b);
    string str3 = str1 + str2;
    string str4 = str2 + str1;
    
    return stoi(str3) > stoi(str4);
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), cmp);
    
    for(int i : numbers){
        answer += to_string(i);
    }
    
    if(numbers[0] == 0){
        answer = "0";
    }
    
    return answer;
}
