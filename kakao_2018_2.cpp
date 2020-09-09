#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    map<string,int> wordList1;
    map<string,int> wordList2;
    int strLen1 = str1.size();
    int strLen2 = str2.size();
    string temp;
    for(int i=0;i<strLen1;++i){
        temp.clear();
        if(str1[i] >= 65 && str1[i] <= 90){
            temp.push_back(str1[i]);
        }
        else if(str1[i] >= 97 && str1[i] <= 122){
            temp.push_back(str1[i] - 32);
        }
        else{
            continue;
        }
        if(str1[i+1] >= 65 && str1[i+1] <= 90){
            temp.push_back(str1[i+1]);
        }
        else if(str1[i+1] >= 97 && str1[i+1] <= 122){
            temp.push_back(str1[i+1] - 32);
        }
        else{
            continue;
        }

        auto it = wordList1.find(temp);
        if(it == wordList1.end()){
            wordList1[temp] = 1;
        } else{
            it->second++;
        }
    }
    
    for(int i=0;i<strLen2;++i){
        temp.clear();
        if(str2[i] >= 65 && str2[i] <= 90){
            temp.push_back(str2[i]);
        }
        else if(str2[i] >= 97 && str2[i] <= 122){
            temp.push_back(str2[i] - 32);
        }
        else{
            continue;
        }
        if(str2[i+1] >= 65 && str2[i+1] <= 90){
            temp.push_back(str2[i+1]);
        }
        else if(str2[i+1] >= 97 && str2[i+1] <= 122){
            temp.push_back(str2[i+1] - 32);
        }
        else{
            continue;
        }
        auto it = wordList2.find(temp);

        if(it == wordList2.end()){
            wordList2[temp] = 1;
        } else{
            it->second++;
        }
    }

    int min=0,max=0;
    for(auto it1=wordList1.begin();it1!=wordList1.end();++it1){
        auto it2 = wordList2.find(it1->first);
        if(it2 ==wordList2.end()){
            continue;
        } else{
            if(it1->second > it2->second){
                min += it2->second;
            }else{
                min += it1->second;
            }
        }
    }
    if(wordList1.size()==0 && wordList2.size()==0){
        min=1;max=1;
    }
    else{
        for(auto it1=wordList1.begin();it1!=wordList1.end();++it1){
            auto it2 = wordList2.find(it1->first);
            if(it2 ==wordList2.end()){
                max += it1->second;
            } else{
                if(it1->second > it2->second){
                    max += it1->second;
                }else{
                    max += it2->second;
                }
                wordList2.erase(it2->first);
            }
        }
        for(auto it=wordList2.begin();it!=wordList2.end();++it){
            max += it->second;
        }
    }
    answer = (min*65536/max);
    return answer;
}
