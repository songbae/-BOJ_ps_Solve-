#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1000001
using namespace std;
int n, k, l;
int m[51][51];
bool check[51][51];
queue<pair<int,pair<int,int>>>q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>>v;
int cnt;
bool ok;
void bfs() {
	for (int T = 0; T < 2000; T++) {
		if (T > 1 && !ok)break;
		ok = false;
		memset(check, false, sizeof(check));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j])continue;
				check[i][j] = true;
				q.push({ m[i][j],{i,j} });
				v.push_back({ i,j });
				int sum = m[i][j];
				while (!q.empty()) {
					int cost = q.front().first;
					int x = q.front().second.first;
					int y = q.front().second.second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						int ncost = m[nx][ny];
						if (nx >= n || ny >= n || nx < 0 || ny < 0)continue;
						if (check[nx][ny])continue;
						if (abs(cost - ncost) >= k && abs(cost - ncost) <= l) {
							check[nx][ny] = true;
							v.push_back({ nx,ny });
							sum += m[nx][ny];
							q.push({ ncost,{nx,ny} });
						}
					}
				}
				for (auto t : v) {
					int x = t.first;
					int y = t.second;
					m[x][y] = sum / v.size();

				}
				if (v.size() >= 2) {
					ok = true;
				}
				v.clear();

			}
		}
		if (ok)cnt++;
	}
}
int main() {
	cin >> n >> k >> l;
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) cin >> m[i][j];
	bfs();
	cout << cnt;
	
}