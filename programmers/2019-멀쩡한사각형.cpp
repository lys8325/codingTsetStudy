#include <iostream>
using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    float d = -(float)h / w;
    float y;
    
    for(int x=1;x<=w;++x){
        y = ( d * x + h ); 
        answer += (long long)y;
    }
    
    return answer*2;
}
