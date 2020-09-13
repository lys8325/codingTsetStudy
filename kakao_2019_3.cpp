#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

bool keyCheck(vector<vector<string>> &relation, set<vector<string>> &rowList, string column){
    int relSize = relation.size();
    int colSize = column.length();
    vector<string> content;
    
    for(int i=0;i<relSize;++i){
        content.clear();
        for(int j=0;j<colSize;++j){
            content.push_back(relation[i][column[j]-'0']);
        }
        if(rowList.find(content)!=rowList.end()){
            rowList.clear();
            return false;
        }else{
            rowList.insert(content);
        }
    }
    rowList.clear();
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    map<string,bool> candiList;
    vector<pair<int,string>> keyLen;
    set<vector<string>> rowList;
    
    for(int i=1;i<5;++i){
        string key;
        string column = "0123";
        vector<int> tmp;
        for(int j=0;j<4-i;++j){
            tmp.push_back(0);
        }
        for(int j=0;j<i;++j){
            tmp.push_back(1);
        }
        do{
            for(int j=0;j<4;++j){
                if(tmp[j] == 1){
                    key += column.substr(j,1);
                }
            }
            candiList[key] = false;
            key.clear();
        }while(next_permutation(tmp.begin(),tmp.end()));
        tmp.clear();
    }
    
    for(auto i=candiList.begin();i!=candiList.end();++i){
        i->second = keyCheck(relation,rowList,i->first);
        if(i->second){
            keyLen.push_back(make_pair(i->first.length(),i->first));   
        }
    }
    sort(keyLen.begin(),keyLen.end());
    
    int index;
    int targetLen;
    int colCheck;
    int keyLenSize = keyLen.length();
    // for(int i=0;i<keyLenSize;++i){
    //     targetLen = keyLen[i].second.length();
    //     while(tmp != candiList.end()){
    //         if(tmp == i){
    //             ++tmp;
    //             continue;
    //         }
    //         colCheck = 0;
    //         for(int a=0;a<index;++a){
    //             if(tmp->first.find(i->first[a]) != -1){
    //                 ++colCheck;
    //             }
    //         }
    //         if(colCheck == index){
    //             candiList.erase(tmp++);
    //         }else{
    //             ++tmp;
    //         }
    //     }
    // }
    
    answer = keyLen.size();
    return answer;
}
