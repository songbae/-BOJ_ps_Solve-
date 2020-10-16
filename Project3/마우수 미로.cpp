#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

char mp[1001][1001];
int n, m;
queue < pair<vector<int>, pair<int, int>>>q;
vector<int>v;
bool check[1001][1001];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
void bfs() {
	while (!q.empty()) {
		vector<int> T = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		if (mp[x][y] == 'D') {
			v = T;
			break;
		}
		for (int i = 0; i < 4; i++) {
			vector<int>P = T;
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx == 0)nx = n;
			 if (nx == n + 1)nx = 1;
			 if (ny == 0)ny = m;
			 if (ny == m+1)ny = 1;
			 if (check[nx][ny])continue;
			 if (mp[nx][ny] == '#')continue;
			 check[nx][ny] = true;
			 P.push_back(nx); P.push_back(ny);
			 q.push({ P,{nx,ny} });
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '#')mp[i][j + 1] = '#';
			if (s[j] == '.')mp[i][j + 1] = '.';
			if (s[j] == 'M') {
				check[i][j + 1] = true;
				mp[i][j + 1] = 'M';
				q.push({ v,{i,j + 1} });
			}
			if (s[j] == 'D')mp[i][j + 1] = 'D';
		}
	}
	bfs();
	if (v.empty()) {
		cout << "NO";
		return 0;
	}
	for (int i = 0; i < v.size()-2; i+=2) {
		mp[v[i]][v[i + 1]] = 'x';
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << mp[i][j];
		}
		cout << endl;
	}
}