#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

// 선택한 후보키 column 에 해당하는 내용으로 벡터를 생성하고, 셋에 등록.
// 이미 존재하면 유일성 x, false return.
// for 문이 모두 진행되면 유일성 o, true return.
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
    int columnLen = relation[0].size();
    map<string,bool> candiList; // (후보키 인덱스 문자열, 유일성 만족 여부)
    vector<pair<int,string>> keyLen; // <유일성 만족한 후보키 인덱스의 길이, 인덱스 문자열> 페어
    set<vector<string>> rowList; // 유일성 만족 검사시 
    
    // column 조합키를 생성하기 위한 문자열
    string column;
    for(int i=0;i<columnLen;++i){
        column += to_string(i);    
    }
    // column 조합키 생성
    for(int i=1;i<columnLen+1;++i){ // i 개의 column 을 선택한 조합.
        string key;
        vector<int> tmp;
        for(int j=0;j<columnLen-i;++j){ // 전체 column 수 - i 개의 column 수 만큼 0 (포함x) 삽입
            tmp.push_back(0);
        }
        for(int j=0;j<i;++j){ // i개의 column 선택을 위한 1 (포함) 삽입.
            tmp.push_back(1);
        }
        do{ // 0*1+ 꼴의 원본 문자의 순서를 바꿔가며 진행.
            for(int j=0;j<columnLen;++j){
                if(tmp[j] == 1){ // 1이면 선택.
                    key += column.substr(j,1);
                }
            }
            candiList[key] = false; // 완성된 조합키, 유일성을 완성하는지에 대한 초기값 false 삽입.
            key.clear();
        }while(next_permutation(tmp.begin(),tmp.end()));
        tmp.clear();
    }
    
    for(auto i=candiList.begin();i!=candiList.end();++i){
        i->second = keyCheck(relation,rowList,i->first); // 유일성 체크 후 값 갱신.
        if(i->second){ // 유일성 만족한다면 <column 수, column 조합> 페어로 삽입.
            keyLen.push_back(make_pair(i->first.length(),i->first)); 
        }
    }
    sort(keyLen.begin(),keyLen.end()); // column 수 오름차순으로 정렬.
    
    int index; // 최소성 검사 위한 타겟 후보키 column 수
    int colCheck; // 몇 개가 겹치는 지
    for(auto i=keyLen.begin();i!=keyLen.end();++i){
        auto tmp = i;
        index = i->first;
        while(tmp != keyLen.end()){
            if(tmp->first == index){ // 같은 iter 일때, 같은 column 수 일 때 continue. 
                ++tmp;
                continue;
            }
            colCheck = 0;
            for(int a=0;a<index;++a){
                if(tmp->second.find(i->second[a]) != -1){ // 후보키 column 이 겹치는 게 있으면 ++colCheck
                    ++colCheck;
                }
            }
            if(colCheck == index){ // 타켓 후보키를 모두 포함한다면, tmp 키는 최소성 탈락.
                if(candiList.find(tmp->second)!=candiList.end()){ // 후보키 리스트에서 삭제.
                    candiList.erase(candiList.find(tmp->second));
                }
            }
            ++tmp;
        }
    }
    
    for(auto i=candiList.begin();i!=candiList.end();++i){ // 최소성 부적합 후보키들을 제거하고 남아있는 후보키 리스트에서
        if(i->second){                                    // 유일성을 만족한 수 구하기
            ++answer;
        }
    }
    
    return answer;
}
