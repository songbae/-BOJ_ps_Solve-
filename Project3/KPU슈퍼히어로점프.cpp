#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1e9
using namespace std;
int n, m;
vector < vector<int>>v;
priority_queue<pair<int,int>>q;
int dist[3501];
void daic(int st, int end) {
	q.push({ 0,st });
	while (!q.empty()) {
		int cost = -q.top().first;
		int x = q.top().second;
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i];
			if (dist[nx] > dist[x] + 1) {
				dist[nx] = dist[x] + 1;
				q.push({-dist[nx], nx });
			}
		}
	}
}
int main() {
	cin >> n >> m;
	v.resize(n + 1);
	fill(dist, dist + n+1, INF);
	for(int i=0; i<m; i++){
		int a,b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int st, target; cin >> st >> target;
	dist[st] = 0;
	daic(st, target);
	if (dist[target] == INF)cout << 0;
	else cout << dist[target];
}