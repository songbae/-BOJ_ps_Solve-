#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1e9
using namespace std;
int n, m, k;
int mp[21][21];
vector<pair<int,int>>v[21][21];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int dist[21][21][21][21];
vector<pair<int, int>>start;
pair<int,int> memo[21][21];
int curx, cury;
bool cmp(pair<int,int> x, pair<int,int> y) {
	int a = dist[curx][cury][x.first][x.second];
	int b = dist[curx][cury][y.first][y.second];
	if (a != b)return a < b;
	if (a == b&&x.first!=y.first)return x.first < y.first;
	if (a == b && x.first == y.first)return x.second < y.second;
}
void floid() {
	for (int k = 0; k < n; k++) for (int p = 0; p < n; p++) 
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) 
	for (int t = 0; t < n; t++) for (int r = 0; r < n; r++) 
	if (dist[i][j][t][r] > dist[i][j][k][p] + dist[k][p][t][r])
	dist[i][j][t][r] = dist[i][j][k][p] + dist[k][p][t][r];
	
}
int main() {
	f; cin >> n >> m >> k;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> mp[i][j];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)for (int t = 0; t < n; t++) for (int p = 0; p < n; p++)dist[i][j][t][p] = INF;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx >= n || ny >= n || nx < 0 || ny < 0)continue;
				if (mp[nx][ny] == 1 || mp[i][j] == 1)continue;
				v[i][j].push_back({ nx,ny });
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < v[i][j].size(); k++) {
				int nx = v[i][j][k].first;
				int ny = v[i][j][k].second;
				dist[i][j][nx][ny] = 1;
				dist[nx][ny][i][j] = 1;
			}
		}
	}
	floid();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j][i][j] = 0;
		}
	}
	cin >> curx >> cury;
	curx--; cury--;
	for (int i = 0; i < m; i++) { 
		int stx, sty, edx, edy; cin >> stx >> sty >> edx >> edy;
		start.push_back({ stx - 1,sty - 1 });
		memo[stx - 1][sty - 1] = { edx - 1,edy - 1 };
	}
	for (int i = 0; i < m; i++) {//
		sort(start.begin(), start.end(), cmp);
		int nx = start[0].first;
		int ny = start[0].second;
		start.erase(start.begin());
		k -= dist[curx][cury][nx][ny];
		if (k <= 0) {
			cout << "-1";
			return 0;
		}
		curx = nx; cury = ny;
		nx = memo[curx][cury].first;
		ny = memo[curx][cury].second;
		if (dist[curx][cury][nx][ny] > k) {
			cout << "-1";
			return 0;
		}
		k += dist[curx][cury][nx][ny];
		curx = nx; cury = ny;
	}
	cout << k;
}