#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1000001
using namespace std;
int n, m;
char arr[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool check[101][101][100];
int ans = 1e9;
queue<pair<pair<int,int>, pair<int, int>>>q;
vector<pair<int, int>>v;
void bfs(pair<int, int>st, pair<int, int>ed) {
	for (int i = 0; i < 4; i++) {
		memset(check, false, sizeof(check));
		q.push({ {0,i},{st} });
		check[st.first][st.second][0] = true;;
		while (!q.empty()) {
			int cnt = q.front().first.first;
			int dir = q.front().first.second;
			int x = q.front().second.first;
			int y = q.front().second.second;
			q.pop();
			if (x == ed.first && y == ed.second) {
				ans = min(cnt, ans);
				continue;
			}
			for (int i = 0; i < 4; i++) {
				int ncnt = cnt;
				if (i == 0&&dir==1)continue;
				if (dir == 0 && i == 1)continue;
				if (dir == 2 && i == 3)continue;
				if (dir == 3 && i == 2)continue;
				if (i != dir)ncnt++;
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= n || ny >= m || nx < 0 || ny < 0)continue;
				if (arr[nx][ny] == '*')continue;
				if (check[nx][ny][ncnt])continue;
				check[nx][ny][ncnt] = true;
				q.push({ {ncnt,i},{nx,ny} });

			}
		}
	}
}
int main() {
	cin >> n >> m;
	swap(n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'C')v.push_back({ i,j });
		}
	}
	bfs(v[0], v[1]);
	cout << ans;
}