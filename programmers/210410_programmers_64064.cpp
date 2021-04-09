#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;

map<string, set<string>> m;

struct trie{
    map<char, trie*> next;
    bool isEnd;
    
    trie(){
        isEnd = false;
    }
    
    ~trie(){
        for(auto it : next){
            delete it.second;
        }
    }
};

void insert(trie *cur, string str, int strLen, int idx){
    if(strLen == idx){
        cur->isEnd = true;
        return;
    }
    
    char c = str[idx];

    if(cur->next.find(c) == cur->next.end()){
        cur->next[c] = new trie();
    }

    insert(cur->next[c], str, strLen, idx+1);
}

void search(trie *cur, string str, int strLen, int idx, string target){
    if(strLen == idx){     
        if(cur->isEnd){
            m[str].insert(target);
        }
        return;
    }
    
    char c = str[idx];
    
    if(c == '*'){
        for(auto it : cur->next){
            target.push_back(it.first);
            search(it.second, str, strLen, idx+1, target);
            target.pop_back();
        }
    }else{
        if(cur->next.find(c) == cur->next.end()){
            return;
        }
        
        target.push_back(c);
        search(cur->next[c], str, strLen, idx+1, target);
        target.pop_back();
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    trie *root = new trie();
    
    for(string str : user_id){
        insert(root, str, str.length(), 0);
    }
    
    for(string str : banned_id){
        search(root, str, str.length(), 0, "");
    }
    
    for(auto it : m){
        cout<<"--"<<it.first<<"--\n";
        for(string str : it.second){
            cout<<str<<"\n";
        }
    }
    
    return answer;
}
