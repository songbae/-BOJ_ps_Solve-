#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 999999
#define MAX 102
using namespace std;
int ans, ans1;
int mp[11][11];
bool check[11][11];
vector<pair<int, int>>v;
int n;
vector<pair<int, int>>odd;
vector<pair<int, int>>prime;
void dfs1(int x, int y, int cnt) {
	ans1 = max(ans1, cnt);
	for (auto t : odd) {
		bool ok = false;
		int nx = t.first;
		int ny = t.second;
		if (nx <= x && ny <= y)continue;
		if (!check[nx][ny]) {
				int dx = nx; int dy = ny;
				while (dx >= 0 && dy >= 0) {
					if (check[dx--][dy--]) {
						ok = true;
						break;
					}
				}
				dx = nx; dy = ny;
				if (ok == false) {
					while (dx >= 0 && dy < n) {
						if (check[dx--][dy++]) {
							ok = true;
							break;
						}
					}
				}
				if (ok)continue;
				check[nx][ny] = true;
				dfs1(nx, ny, cnt + 1);
				check[nx][ny] = false;
			}
		}
	return;
}
void dfs(int x, int y, int cnt) {//헹,열 , 현재까지 개수
	ans = max(cnt, ans);
	for (auto t : prime) {//검정칸 
		bool ok = false;
		int nx = t.first;
		int ny = t.second;
		if (nx <= x && ny <= y)continue;//전값보다 작은건 패스
		if (!check[nx][ny]) {
			int dx = nx; int dy = ny;
			while (dx>=0&&dy>=0) {
				if (check[dx--][dy++]) {
					ok = true;
					break;
				}
			}
			dx = nx; dy = ny;
			if (ok == false) {
				while (dx >= 0 && dy<n) {
					if (check[dx--][dy++]) {
						ok = true;
						break;
					}
				}
			}
				if (ok)continue;//체크되어있다면 pass
				check[nx][ny] = true;
				dfs(nx, ny, cnt + 1);
				check[nx][ny] = false;
			}
		}
	return;
}
int main() {
	cin >> n; f;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		cin >> mp[i][j];
		if (mp[i][j] == 1 && (i + j) % 2 == 0)prime.push_back({ i, j });
		if (mp[i][j] == 1 && (i + j) % 2 == 1)odd.push_back({ i, j });
	}

	for (auto t : prime) {//짝수 dfs
		check[t.first][t.second] = true;
		dfs(t.first, t.second, 1);
		check[t.first][t.second] = false;
	}
	for (auto t : odd) {//홀수 dfs
		check[t.first][t.second] = true;
		dfs1(t.first, t.second, 1);
		check[t.first][t.second] = false;
	}
	cout << ans + ans1;
}