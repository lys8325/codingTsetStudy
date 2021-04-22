#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#define INF 1000000000
using namespace std;

int dijk[51];
map<int, vector<pair<int, int>>> ad;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    int from, to, w, cost, city, nextCity, nextCost;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for(int i=1;i<=N;++i){
        dijk[i] = INF;
    }
    
    for(vector<int> v : road){
        from = v[0];
        to = v[1];
        w = v[2];
        
        ad[from].push_back({to, w});
        ad[to].push_back({from, w});
    }
    
    pq.push({0, 1});
    dijk[1] = 0;
    
    while(!pq.empty()){
        cost = pq.top().first;
        city = pq.top().second;
        pq.pop();
        
        if(cost <= dijk[city]){
            for(pair<int, int> p : ad[city]){
                nextCity = p.first;
                nextCost = cost + p.second;
                
                if(nextCost < dijk[nextCity]){
                    dijk[nextCity] = nextCost;
                    pq.push({nextCost, nextCity});
                }
            }
        }
    }
    
    for(int i=1;i<=N;++i){
        if(dijk[i] <= K){
            ++answer;
        }
    }

    return answer;
}
