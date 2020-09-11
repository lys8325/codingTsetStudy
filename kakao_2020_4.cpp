#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<int> qLen;
    int wSize = words.size();
    int qSize = queries.size();
    int index;
    int matchCount;
    string temp;
    bool isFront = false;
    bool full = false;
    map<string, int> matchList;
    string copy;
    for(int i=0;i<qSize;++i){
        //copy = queries[i]; // 왜 여기에서 복사하면 틀리는지 이해안감...
        if(matchList.find(copy) != matchList.end()){
            copy = queries[i];
            answer.push_back(matchList[copy]);
        }else{
            copy = queries[i];
            index = 0;
            matchCount = 0;
            isFront = false;
            full = false;
            qLen.push_back(copy.length());
            if(copy[0] == '?'){
                isFront = true;
            }
            while(copy.find("?") != -1){
                ++index;
                copy.erase(copy.find("?"),1);
            }

            if(copy.length() == 0){
                isFront = false;
                full = true;
            }

            for(int j=0;j<wSize;++j){
                if(words[j].length()!=qLen[i]){
                    continue;
                }
                if(full){
                    ++matchCount;
                }else if(isFront){
                    temp = words[j].substr(index);
                    if(temp == copy){
                        ++matchCount;
                    }
                }else{
                    temp = words[j].substr(copy.length());
                    if(temp.length() == index && words[j].find(copy) == 0){
                        ++matchCount;
                    }
                }
            }
            answer.push_back(matchCount);
            matchList[queries[i]]=matchCount;
        }
    }
    // for(auto i=matchList.begin();i!=matchList.end();++i){
    //     cout<<i->first<<" : "<<i->second<<endl;
    // }
    return answer;
}
