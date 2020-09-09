#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 입력받은 시간정보를 hh:mm 형태의 string 으로 반환
string makeTimeString(int hour, int min){
    string tempTime;
    if(hour<10){
        tempTime += ("0" + to_string(hour) + ":");
    }else{
        tempTime += (to_string(hour) + ":");
    }
    if(min<10){
        if(min == 0){
            tempTime += "00";
        }else{
            tempTime += ("0" + to_string(min));   
        }
    }else{
        tempTime += to_string(min); 
    }
    return tempTime;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    sort(timetable.begin(),timetable.end());

    int startHour = stoi("09");
    int startMin = stoi("00");
    int index = 0;
    
    for(int i=0;i<n;++i){
        int hour = 0;
        int min = i*t;
        if(min >= 60){
            hour = min / 60;
            min = min - (hour * 60);
        }
        hour += startHour;
        min += startMin;
        string busTime = makeTimeString(hour,min);
        
        if(i < n-1){ // 막차가 아니면 탑승 진행
            for(int j=0;j<m;++j){
                if(timetable[index] <= busTime){
                    ++index;
                }
            }
        }else{ // 막차일 경우
            for(int j=0;j<m-1;++j){ // m-1턴까지 진행
                if(timetable[index] <= busTime){
                    ++index;
                }
            }
            if(index == timetable.size()){ // 마지막 1자리가 남았을 때, 이미 모든 대기열이 탑승했다면,
                answer = busTime;           // 버스 도착시간에 맞춰서 대기
            }else{ // 대기열이 남아 있다면, 버스 도착시간과 (다음 순번의 대기열 시간정보 - 1분 ) 중 빠른 시간 선택
                hour =  stoi(timetable[index].substr(0,2));
                min = stoi(timetable[index].substr(3,2))-1;
                string tempTime;
                if(min<0){
                    min=59;
                    --hour;
                }
                if(hour<10){
                    tempTime += ("0" + to_string(hour) + ":");
                }else{
                    tempTime += (to_string(hour) + ":");
                }
                if(min<10){
                    if(min == 0){
                        tempTime += "00";
                    }else{
                        tempTime += ("0" + to_string(min));   
                    }
                }else{
                    tempTime += to_string(min); 
                }
                
                if(tempTime > busTime){
                    answer = busTime;
                }else{
                    answer = tempTime;
                }
            }
        }
    }
    return answer;
}
