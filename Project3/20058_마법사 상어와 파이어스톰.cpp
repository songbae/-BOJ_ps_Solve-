#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int mp[65][65];
int c_mp[65][65];
int n, m;
bool check[65][65];
vector<pair<int, int>>v;
queue<pair<int,int>>q;
int ans;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
void bfs() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j])continue;
			if (mp[i][j] == 0)continue;
			int cnt = 1;
			check[i][j] = true;
			q.push({ i,j });
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				ans = max(cnt, ans);
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx >= n || ny >= n || nx < 0 || ny < 0)continue;
					if (mp[nx][ny] == 0)continue;
					if (check[nx][ny])continue;
					check[nx][ny] = true;
					cnt++;
					q.push({ nx,ny });
				}
			}
		}
	}
}
void move(int a) {
	int k=n/a;
	int start = n / k;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				for(int aa=i*start; aa<start*(i+1);aa++){
					for (int bb = j * start; bb < start * (j + 1); bb++) {
						c_mp[start*i-(j*start-bb)][(j+1) * start-1 - (aa-i*start)] = mp[aa][bb];
					}
				}

			}
		}
		
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) mp[i][j] = c_mp[i][j];
		cout << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << mp[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++) {
				int num = 0;
				if (mp[i][j] == 0)continue;
				for (int T = 0; T < 4; T++) {
					int nx = i + dx[T];
					int ny = j + dy[T];
					if (nx >= n || ny >= n || nx < 0 || ny < 0)continue;
					if (mp[nx][ny] == 0)continue;
					num++;
				}
				if (num < 3)v.push_back({ i,j });
			}
		}
		for (auto t : v) mp[t.first][t.second]--;
		v.clear();
}
int main() {
	cin >> n >> m;
	n = pow(2, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		memset(c_mp, false, sizeof(c_mp));
		a = pow(2, a);
		move(a);
	}
	bfs();
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += mp[i][j];
		}
	}
	cout << sum << endl;
	cout << ans;
}