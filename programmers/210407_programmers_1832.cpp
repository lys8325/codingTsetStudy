#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int MOD = 20170805;

int endY, endX;
int arrive[500][500][2];
int dy[2] = {1, 0};
int dx[2] = {0, 1};

int dfs(int y, int x, int d, vector<vector<int>> &city_map){
    if(y < 0 || y > endY || x < 0 || x > endX){
        return 0;
    }
    
    if(y == 0 && x == 0){
        return 1;
    }

    int &v = arrive[y][x][d];

    if(v != -1){
        return v;
    }

    int nextY, nextX;

    if(city_map[y][x] == 1){
        v = 0;
        return 0;
    }else if(city_map[y][x] == 2){
        nextY = y - dy[d];
        nextX = x - dx[d];

        v = dfs(nextY, nextX, d, city_map) % MOD;
        return v;
    }else{
        v = 0;
        for(int i=0;i<2;++i){
            nextY = y - dy[i];
            nextX = x - dx[i];

            v += dfs(nextY, nextX, i, city_map) % MOD;
        }
    }

    return v % MOD;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0, nextY, nextX;
    endY = m-1;
    endX = n-1;

    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            for(int p=0;p<2;++p){
                arrive[i][j][p] = -1;
            }
        }
    }
    
    for(int i=0;i<2;++i){
        nextY = endY - dy[i];
        nextX = endX - dx[i];
        
        answer += dfs(nextY, nextX, i, city_map);
    }

    return answer % MOD;
}
