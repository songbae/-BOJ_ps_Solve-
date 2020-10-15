#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
char arr[11][11];
pair<int, int>cur;
pair<int, int>target;
queue<pair<int, pair<int, int>>>q;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool check[11][11];
int answer = 1e9;
void bfs(pair<int, int>a, pair<int, int>b) {
	q.push({ 0,a });
	while (!q.empty()) {
		int x = q.front().second.first;
		int y = q.front().second.second;
		int cost = q.front().first;
		q.pop();
		if (arr[x][y] == 'L')answer = min(answer,cost);
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 10 || ny >= 10 || nx < 0 || ny < 0)continue;
			if (arr[nx][ny] == 'R')continue;
			if (check[nx][ny])continue;
			check[nx][ny] = true;
			q.push({ cost+1,{nx,ny} });
		}
	}
}
int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'B')cur = { i,j };
			if (arr[i][j] == 'L')target = { i,j };
		}
	}
	bfs(cur,target);
	cout << answer-1;
}