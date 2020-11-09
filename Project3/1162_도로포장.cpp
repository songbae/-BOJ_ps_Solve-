#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1e9
using namespace std;
vector < vector<pair<int, int>>>v;
int n, m, k;
int dist[10001];
int path[10001];
int memo[10001][10001];
vector<int>ans;
priority_queue<pair<int, int>>pq;

void Find(int n) {
	if (n == 1)return;
	else {
		ans.push_back(memo[n][path[n]]);
		Find(path[n]);
	}
	return;
}
void daic(int st, int target) {
	pq.push({ 0,1 });
	path[1] = 1;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int ncost = v[now][i].second;
			if (dist[next] > dist[now] + ncost) {
				dist[next] = dist[now] + ncost;
				path[next] = now;
				pq.push({ -ncost,next });
			}
		}
	}

}
int main() {
	cin >> n>>m>>k;
	v.resize(n + 1);
	fill(dist, dist + n + 1, INF);
	for (int i = 0; i < m; i++) {
		int a, b, val; cin >> a >> b >> val;
		v[a].push_back({ b,val });
		v[b].push_back({ a,val });
		memo[a][b] = val;
		memo[b][a] = val;
	}
	dist[1] = 0;
	daic(1,n);
	Find(n);
	sort(ans.begin(), ans.end());
	for (int i = 1; i <= n; i++)cout << dist[i] << " ";
	cout << endl;
	for (int i = 1; i <= n; i++)cout << path[i] << " ";
	cout << endl;
	for (auto T : ans)cout << T << " ";
	while (k--)ans.pop_back();
	int sum = 0;
	for (auto T : ans)sum += T;
	cout << sum;
}