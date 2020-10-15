#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool mat[10][10];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
vector<int> ans;
queue<pair<int, int>> q;
int n;

int bfs(int y, int x){
	int cnt = 1;
	int tmpY, tmpX, nextY, nextX;
	mat[y][x] = false;
	q.push(make_pair(y, x));

	while(!q.empty()){
		tmpY = q.front().first;
		tmpX = q.front().second;
		q.pop();

		for(int i=0;i<4;++i){
			nextY = tmpY + dy[i];
			nextX = tmpX + dx[i];

			if(nextY < 0 || nextY >= n || nextX < 0 || nextX >= n){
				continue;
			}

			if(mat[nextY][nextX]){
				q.push(make_pair(nextY, nextX));
				mat[nextY][nextX] = false;
				++cnt;
			}
		}
	}

	return cnt;
}

int main(){
	cin>>n;
	int len = 0;

	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>mat[i][j];
		}
	}

	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(mat[i][j]){
				ans.push_back(bfs(i, j));
				++len;
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout<<len<<"\n";
	for(int i=0;i<len;++i){
		if(i < len-1){
			cout<<ans[i]<<" ";
		}else{
			cout<<ans[i]<<"\n";
		}
	}

	return 0;
}
