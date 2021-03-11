#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct depth{
    int nodeNum;
    int depth;
};

bool visit[20001];

int solution(int n, vector<vector<int>> edge) {
    int maxDepth = -1;
    int answer = 0;
    int edgeSize = edge.size();
    vector<vector<int>> node(n+1);
    queue<depth> q;
    vector<depth> v;
    
    int from, to;
    for(int index=0;index<edgeSize;++index){
        from = edge[index][0];
        to = edge[index][1];
        
        node[from].push_back(to);
        node[to].push_back(from);
    }
    
    
    q.push({1, 0});
    visit[1] = true;
    v.push_back({1, 0});
    while(!q.empty()){
        int nodeNum = q.front().nodeNum;
        int curDepth = q.front().depth;
        maxDepth = max(maxDepth, curDepth);
        q.pop();
        
        int edgeInfoSize = node[nodeNum].size();
        for(int index=0;index<edgeInfoSize;++index){
            if(!visit[node[nodeNum][index]]){
                visit[node[nodeNum][index]] = true;
                q.push({node[nodeNum][index], curDepth+1});   
                v.push_back({node[nodeNum][index], curDepth+1});
            }
        }
    }
    
    for(auto iter : v){ 
        if(iter.depth == maxDepth){
            ++answer;
        }
    }
    
    return answer;
}
