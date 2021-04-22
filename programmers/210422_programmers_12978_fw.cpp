#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;

int fw[51][51];

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    int from, to, w;
    
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            if(i == j){
                fw[i][j] = 0;
            }else{
                fw[i][j] = INF;
            }
        }
    }
    
    for(vector<int> v : road){
        from = v[0];
        to = v[1];
        w = v[2];
        
        fw[from][to] = min(fw[from][to], w);
        fw[to][from] = min(fw[to][from], w);
    }
    
    for(int k=1;k<=N;++k){
        for(int i=1;i<=N;++i){
            for(int j=1;j<=N;++j){
                fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
            }
        }
    }
    
    for(int i=1;i<=N;++i){
        if(fw[1][i] <= K){
            ++answer;
        }
    }

    return answer;
}
