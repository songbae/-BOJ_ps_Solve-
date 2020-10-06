#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 500001
using namespace std;
char mp[501][501];
bool check[501][501];
int n, m;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans;
int change(char k) {
	if (k == 'D')return 2;
	if (k == 'U')return 3;
	if (k == 'R')return 0;
	if (k == 'L')return 1;
}
void dfs(int x, int y) {
	if (x >= n || y >= m || x < 0 || y < 0) {
		ans++;
		return;
	}
	char c = mp[x][y];
	int nx = x + dx[change(c)];
	int ny = y + dy[change(c)];
	check[nx][ny] = true;
	dfs(nx, ny);
	check[nx][ny] = false;
	return;
}
int main() {
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			mp[i][j] = s[j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			check[i][j] = true;
			dfs(i, j);
			check[i][j] = false;
		}
	}
	cout << ans;
}