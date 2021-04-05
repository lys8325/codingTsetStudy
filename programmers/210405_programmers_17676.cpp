#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> startTime;
vector<int> endTime;

vector<string> parse(string str, char c){
    vector<string> ret;
    int cur = 0, prev = 0;

    cur = str.find(c);
    while(cur != -1){
        ret.push_back(str.substr(prev, cur-prev));
        prev = cur + 1;
        cur = str.find(c, prev);
    }
    ret.push_back(str.substr(prev, -1));

    return ret;
}

void makeTimeTable(vector<string> &v){
    vector<string> num = parse(v[1], ':');
    int sum = 0;

    sum += stoi(num[0]) * 1000 * 60 * 60;
    sum += stoi(num[1]) * 1000 * 60;
    sum += stof(num[2]) * 1000;

    startTime.push_back(sum - (stof(v[2])*1000) + 1);
    endTime.push_back(sum);
}

bool checkPossible(int s, int e, int index){
    int targetStart = startTime[index];
    int targetEnd = endTime[index];
    bool ret = false;
    
    if(targetStart >= s && targetStart <= e){
        ret = true;
    }else if(targetEnd >= s && targetEnd <= e){
        ret = true;
    }else if(targetStart <= s && targetEnd >= e){
        ret = true;
    }
    
    return ret;
}

int solution(vector<string> lines) {
    int answer = -1;
    int len = lines.size();
    int cnt;
    
    for(string str : lines){
        vector<string> v = parse(str, ' ');
        v[2].pop_back();
        makeTimeTable(v);
    }

    for(int i=0;i<len;++i){
        cnt = 0;
        for(int j=0;j<len;++j){
            if(checkPossible(startTime[i], startTime[i]+999, j)){
                ++cnt;
            }
        }
        answer = max(answer, cnt);

        cnt = 0;
        for(int j=0;j<len;++j){
            if(checkPossible(endTime[i], endTime[i]+999, j)){
                ++cnt;
            }
        }
        answer = max(answer, cnt);
    }

    return answer;
}
