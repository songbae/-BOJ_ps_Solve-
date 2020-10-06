#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1e9
using namespace std;
priority_queue<pair<int, int>>q;
vector<vector<int>>v;
int n, m;
int dist[20001];
int big;
void dik() {
	while (!q.empty()) {
		int cost =- q.top().first;
		int x = q.top().second;
		q.pop();
			for (int i = 0; i < v[x].size(); i++) {
				int next = v[x][i];
				if (dist[next] > dist[x] + 1) {
					dist[next] = dist[x] +1;
					q.push({ -dist[next], next });
				}
			}
	}

}
int main() {
	int st, end; cin >> n; cin >> st >> end;
	fill(dist, dist + n+1, INF);
	v.resize(n + 1);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dist[st] = 0;
	q.push({ 0, st });
	dik();
	if (dist[end] == INF)cout << "-1";
	else cout << dist[end];
}