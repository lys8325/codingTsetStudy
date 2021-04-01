#include <string>
#include <vector>

using namespace std;

void go(int from, int to, vector<vector<int>> &answer){
    vector<int> v;
    v.push_back(from);
    v.push_back(to);
    answer.push_back(v);
}

void hanoi(int n, int from, int to, int via, vector<vector<int>> &answer){
    if(n == 1){
        go(from, to, answer);
    }else{
        hanoi(n-1, from, via, to, answer);
        go(from, to, answer);
        hanoi(n-1, via, to, from, answer);
    }
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 3, 2, answer);
    return answer;
}
