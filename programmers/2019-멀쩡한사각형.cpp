#include <iostream>
using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    long long y;
    
    for(int x=1;x<=w;++x){
        y = ( -(double)h * x / w + h ); 
        answer += y;
    }
    
    return answer*2;
}
