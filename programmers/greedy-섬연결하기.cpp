#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node{
    int from;
    int to;
    int weight;
};

struct cmp{
    bool operator()(node n1, node n2){
        return n1.weight > n2.weight;
    }
};



int root[100];
priority_queue<node, vector<node>, cmp> pq;

int findRoot(int num){
    if(num == root[num]){
        return num;
    }
    
    return root[num] = findRoot(root[num]);
}

void unionRoot(int num1, int num2){
    int root1 = findRoot(num1);
    int root2 = findRoot(num2);
    
    if(root1 < root2){
        root[root2] = root1;
    }else{
        root[root1] = root2;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int costsSize = costs.size();
    
    for(int i=0;i<costsSize;++i){
        pq.push({costs[i][0], costs[i][1], costs[i][2]});
    }
    
    for(int i=0;i<n;++i){
        root[i] = i;
    }
    
    int cnt = 0, sum = 0;
    while(cnt < n-1){
        if(findRoot(pq.top().from) != findRoot(pq.top().to)){
            ++cnt;
            sum += pq.top().weight;
            unionRoot(pq.top().from, pq.top().to);
        }
        pq.pop();
    }
    
    return answer = sum;
}
