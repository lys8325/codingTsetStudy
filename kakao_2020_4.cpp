#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

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
        copy = queries[i];
        qLen.push_back(copy.length());
        if(matchList.find(copy) != matchList.end()){
            answer.push_back(matchList[copy]);
        }else{
            index = 0;
            matchCount = 0;
            isFront = false;
            full = false;
            if(copy[0] == '?'){
                isFront = true;
                if(copy[qLen[i]-1] == '?'){
                    isFront = false;
                    full = true;
                }
            }
            if(!full){
                if(isFront){
                    reverse(copy.begin(),copy.end());   
                }
                copy.erase(copy.find('?'));
                index = qLen[i] - copy.length();
                if(isFront){
                    reverse(copy.begin(),copy.end());
                }
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
    return answer;
}
