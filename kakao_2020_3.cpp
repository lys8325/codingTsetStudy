#include <string>
#include <vector>
#include <iostream>

using namespace std;

// key 90도 회전
void rotateKey(vector<vector<int>> &key, int keySize){
    vector<vector<int>> copyKey = key;
    for(int i=0;i<keySize;++i){
        for(int j=0;j<keySize;++j){
            key[j][keySize-1-i] = copyKey[i][j];
        }
    }
}

// 확장된 lock에 키를 맞춰보기
bool checkKey(vector<vector<int>> &key, vector<vector<int>> lock, int keySize, int lockSize, int y, int x){
    // 확장된 lock에서 키가 시작하는 좌표를 넘겨받으면, 그곳에서 부터 lock을 계산.
    for(int i=0;i<keySize;++i){
        for(int j=0;j<keySize;++j){
            lock[i+y][j+x] += key[i][j];
            if(lock[i+y][j+x] == 2){ // 원래 lock 영역에서 맞닿는 부분이 발생하면 false;
                return false;        // 원래 lock 영역에서 안 맞물려서 0이어도 false지만 확장된 영역,
                                     // 키가 빠져 나온 부분은 가지치기에 해당 하지 않으니, 여기서는 확실한 실패값인 2만을 체크
            }
        }
    }
    
    // 위 과정까지 모두 진행이 되었다면, 원래 lock 영역에 1이 아닌 영역이 있는지 체크
    for(int i=keySize-1;i<lockSize-keySize+1;++i){
        for(int j=keySize-1;j<lockSize-keySize+1;++j){
            if(lock[i][j] != 1){ // 빈 곳, 0 이 발견되었다면 false return ( 2인 부분은 앞 과정에서 가지치기)
                return false;
            }
        }
    }
    
    return true; // 모두 통과했다면 true 반환
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int keySize = key.size();
    int lockSize = lock.size();
    int newLockSize = lockSize + keySize + keySize - 2;
    vector<vector<int>> newLock;
    
    // 키가 lock에서 벗어 날 수도 있기 때문에 (key-1) * 2 만큼 확장
    for(int i=0;i<=newLockSize;++i){
        vector<int> temp;
        for(int j=0;j<=newLockSize;++j){
            if(
                i < keySize-1 ||
                i > newLockSize - keySize ||
                j < keySize-1 ||
                j > newLockSize - keySize
            ){
                temp.push_back(0);
            }else{
                temp.push_back(lock[i-keySize+1][j-keySize+1]);
            }
        }
        newLock.push_back(temp);
        temp.clear();
    }
    
    for(int i=0;i<4;++i){ // key 방향 경우의 수 만큼
        for(int j=0;j<newLockSize-keySize+1;++j){
            for(int k=0;k<newLockSize-keySize+1;++k){
                answer = checkKey(key, newLock, keySize, newLockSize, j, k);
                if(answer){
                    return answer;
                }
            }
        }
        rotateKey(key, keySize);
    }
    
    return answer;
}
