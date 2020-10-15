#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string,string> userList;
    vector<pair<string,string>> logList;
    for(int i=0;i<record.size();++i){
        string original = record[i];
        string mode,uid,name;
        mode = original.substr(0,original.find(' '));
        original = original.substr(mode.size()+1);
        uid = original.substr(0,original.find(' '));
        logList.push_back(make_pair(uid,mode));
        if(mode == "Leave"){
            continue;
        }
        original = original.substr(uid.size()+1);
        name = original.substr(0,original.find(' '));
        userList[uid]=name;
    }
    for(int i=0;i<logList.size();++i){
        string uid = logList[i].first;
        string mode = logList[i].second;
        string log;
        if(mode == "Enter"){
            log = userList[uid] + "님이 들어왔습니다.";
            answer.push_back(log);
        }
        else if(mode == "Leave"){
            log = userList[uid] + "님이 나갔습니다.";
            answer.push_back(log);
        }
    }
    return answer;
}
