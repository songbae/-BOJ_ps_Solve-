#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int n, m,cnt,ans;
int Map[21][21];
bool check[27];
string s;
void bfs(int x, int y, int cnt) {
	ans = max(cnt, ans);
	if (cnt >= 26)return;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= n || ny >= m || nx < 0 || ny < 0)continue;
		if (check[Map[nx][ny]])continue;
		check[Map[nx][ny]] = true;
		bfs(nx, ny,cnt+1);
		check[Map[nx][ny]] = false;
	}
	return;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			Map[i][j] = s[j] - 65;
		}
	}
	check[Map[0][0]] = true;
	bfs(0,0,1);
	cout << ans;
}