#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is4Block[30][30] = {false};
bool success = true;

void find4Block(char target, int i, int j, vector<string> &board){
        if(
            board[i][j+1] == target &&
            board[i+1][j] == target &&
            board[i+1][j+1] == target
        ){
            is4Block[i][j] = true;
            is4Block[i][j+1] = true;
            is4Block[i+1][j] = true;
            is4Block[i+1][j+1] = true;
            success = true; // 터지고 난 후에 반복하도록!
        }
    }

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    char target;
    int eraseCount[30] = {0};
    
    while(success){
        success = false;
        for(int i=0;i<m-1;++i){
            for(int j=0;j<n-1;++j){
                target = board[i][j];
                if(target == '0'){
                    continue;
                }
                find4Block(target,i,j,board);
            }
        }
        // 체크한 블럭 터트리고, 체크 리셋, ++결과, ++열의 공백
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(is4Block[i][j]){
                    board[i][j] = '0';
                    is4Block[i][j] = false;
                    ++eraseCount[j];
                    ++answer;
                }
            }
        }
        // 열에 공백이 있으면 중력 적용
        for(int j=0;j<n;++j){
            if(eraseCount[j] == 0){
                continue;
            }
            // temp 를 0으로 채우고, 뒤에서부터 0이 아니면 블럭으로 수정.
            string temp(m,'0');
            int pos = m-1;
            for(int i=m-1;i>=0;--i){
                if(board[i][j] != '0'){
                    temp[pos--]=board[i][j]; // 다음 블럭위치 갱신
                }
            }
            // 보드 갱신
            for(int i=0;i<m;++i){
                board[i][j] = temp[i];
            }
        }
    }
    return answer;
}
