#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 500001
using namespace std;
int mp[11][11];
bool check[11][11];
bool island[7];
bool ok[100];
int n, m;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int num = 1;
int parent[7];
int ans = 1e9;
vector<pair<int, pair<int, int>>>connect;
vector <vector< pair<int, int>>>v;
queue<pair<int, int>>q;

void bfs(int x,int y) {
	q.push({ x,y });
	check[x][y] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		v[num].push_back({ x,y });
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= n || ny >= m || nx < 0 || ny < 0)continue;
			if (check[nx][ny])continue;
			check[nx][ny] = true;
			mp[nx][ny] = num;	
				q.push({ nx,ny });
		}

	}
	num++;
	return;
}
void bridge() {
	for (int i = 0; i < 7; i++) {
		if (v[i].size() == 0)break;
		for (int j = 0; j < v[i].size(); j++) {
			int x = v[i][j].first;
			int y = v[i][j].second;
			for (int p = 0; p < 4; p++) {
			for (int k = 1; k < 9; k++) {
					int nx = x + dx[p] * k;
					int ny = y + dy[p] * k;
					if (mp[nx][ny] == mp[x][y])break;
					if (mp[nx][ny] != 0 && k < 2)break;
					connect.push_back({ k - 1,{mp[x][y],mp[nx][ny]} });
					break;

				}
			}
		}
	}
	return;
}
int find(int x) {
	if (parent[x] == x)return x;
	return parent[x] = find(x);
}
bool Union(int x, int y) {
	int nx = find(x);
	int ny = find(y);
	if (nx == ny)return false;
	if (nx < ny)parent[ny] = nx;
	if (nx > ny)parent[nx] = ny;
	return true;
}
void dfs(int index, int cnt, int target) {
	if (cnt == target - 1) {
		int all = 0;
		for (int i = 1; i <= target; i++) if (parent[i] == i)all++;
		if (all == 1) {
			int sum = 0;
			for (int i = 0; i < connect.size(); i++) {
				if (ok[i])sum += connect[i].first;
			}
			ans = min(sum, ans);
		}
	}
	for (int i = 0; i < connect.size(); i++) {
		if (!ok[i]) {
			int x = connect[i].second.first;
			int y = connect[i].second.second;
			int nx = parent[x]; int ny = parent[y];
			if (!Union(x, y))continue;
			ok[i] = true;
			dfs(i, cnt + 1, target);
			ok[i] = false;
			parent[x] = nx; parent[y] = ny;
		}
	}
}

int main() {
	cin >> n >> m;
	v.resize(7);
	for (int i = 0; i < 7; i++)parent[i] = i;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)cin >> mp[i][j];
for(int i=0;i<n; i++)for(int j=0; j<m; j++)if(mp[i][j]==1&&!check[i][j])bfs(i,j);//여기까지 그룹화 끝
//그룹화 끝났으니 이제 다리 연결하기 
for (int i = 1; i <= num; i++)parent[i] = i;//각 그룹에 대해서 유니온 파인드 할예정 
	bridge();//모든 다리를 구했다 .
	//이제 다리를 선택해서 이은다음- 연결되어있는지를 확인한다.
	dfs(0,0,num);
	cout << ans;
}