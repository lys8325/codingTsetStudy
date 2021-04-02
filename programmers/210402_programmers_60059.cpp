#include <string>
#include <vector>
#include <iostream>

using namespace std;

void rotateKey(vector<vector<int>> &key, int keySize){
    vector<vector<int>> copyKey = key;
    for(int i=0;i<keySize;++i){
        for(int j=0;j<keySize;++j){
            key[j][keySize-1-i] = copyKey[i][j];
        }
    }
}

bool checkKey(vector<vector<int>> &key, vector<vector<int>> lock, int keySize, int lockSize, int y, int x){
    for(int i=0;i<keySize;++i){
        for(int j=0;j<keySize;++j){
            lock[i+y][j+x] += key[i][j];
            if(lock[i+y][j+x] == 2){
                return false;
            }
        }
    }
    
    for(int i=keySize-1;i<lockSize-keySize+1;++i){
        for(int j=keySize-1;j<lockSize-keySize+1;++j){
            if(lock[i][j] != 1){
                return false;
            }
        }
    }
    
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int keySize = key.size();
    int lockSize = lock.size();
    int newLockSize = lockSize + keySize + keySize - 2;
    vector<vector<int>> newLock;
    
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
    
    for(int i=0;i<4;++i){
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
