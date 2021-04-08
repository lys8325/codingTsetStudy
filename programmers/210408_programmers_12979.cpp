#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> v;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int left = 1, right = n, len, mod = 2*w+1;
    
    for(int i : stations){
        len = i-w-left;
        if(len < 0){
            len = 0;
        }
        answer += ceil(float(len) / mod);
        
        left = i+w+1;
    }
    
    len = n - stations[stations.size()-1] - w;
    if(len < 0){
        len = 0;
    }
    answer += ceil(float(len) / mod);
    
    
    return answer;
}
