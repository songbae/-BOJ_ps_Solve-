#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
vector < vector<pair<int, int>>>v;
int depth[101];
vector<pair<int, int>> toy[101];
queue<int>q;
bool check[101];
int num[101][101];
void topology() {
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			int cnt = v[x][i].second;
			toy[nx].push_back({ x,cnt });
			if (--depth[nx] == 0) {
				q.push(nx);
			}
		}
	}
}
int main() {
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[b].push_back({ a,c });
		depth[a]++;
	}
	for (int i = 1; i <= n; i++) {
		if (depth[i] == 0) {
			check[i] = true;
			q.push(i);
		}
	}
	topology();
	for (int i = 1; i <= n; i++) {
		if (!check[i])continue;
		int x = i;
		int cnt = 1;
		for (int j = i + 1; j <= n; j++) {
			if (check[j])continue;
			for (int k = 0; k < toy[j].size(); k++) {
				if (x == toy[j][k].first) {
					x = j;
					cnt *= toy[j][k].second;
					break;
				}
			}
		num[j][i] += cnt;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i])continue;
		cout << i << " " << num[i] << endl;
	}
}