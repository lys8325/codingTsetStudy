#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> v1, vector<int> v2){
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int maxEnd = -30001;
    int routesSize = routes.size();
    
    sort(routes.begin(), routes.end(), cmp);
    for(int i=0;i<routesSize;++i){
        if(routes[i][0] > maxEnd){
            ++answer;
            maxEnd = routes[i][1];
        }
    }
    
    return answer;
}
