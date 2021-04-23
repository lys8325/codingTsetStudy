#include<vector>
#include <queue>
using namespace std;

struct state{
    int y;
    int x;
    int cnt;
};

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int visit[100][100];

int bfs(vector<vector<int>> &maps){
    int yLen = maps.size()-1;
    int xLen = maps[0].size()-1;
    int ret = -1;
    int curY, curX, curCnt, nextY, nextX;
    queue<state> q;
    
    q.push({0, 0, 1});
    visit[0][0] = true;
    
    while(!q.empty()){
        curY = q.front().y;
        curX = q.front().x;
        curCnt = q.front().cnt;
        q.pop();
        
        if(curY == yLen && curX == xLen){
            ret = curCnt;
            break;
        }
        
        for(int i=0;i<4;++i){
            nextY = curY + dy[i];
            nextX = curX + dx[i];
            
            if(nextY >= 0 && nextY <= yLen && nextX >= 0 && nextX <= xLen && maps[nextY][nextX] == 1 && !visit[nextY][nextX]){
                visit[nextY][nextX] = true;
                q.push({nextY, nextX, curCnt+1});
            }
        }
    }
    
    return ret;
}

int solution(vector<vector<int> > maps)
{
    int answer = bfs(maps);
    return answer;
}
