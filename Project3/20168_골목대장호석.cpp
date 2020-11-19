#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
#define INF 1e9
int n, m, c, a, b,st,ed;
long long money;
vector<vector<pair<int, int>>>v;
long long dist[100001];
vector<int>ans;
priority_queue<pair<long long,int>>q;// 다음위치랑, 가중치,현재값,최대값
int diac(int s, int e, int num) {
	q.push({ 0,s });
	while (!q.empty()) {
		int x = q.top().second;
		long long cost = -q.top().first;
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].second;
			long long ncost = v[x][i].first;
			if (ncost > num)continue;
			if (dist[nx]>dist[x]+ncost) {
				dist[nx] = dist[x] + ncost;
				q.push({ -dist[nx],nx });
			}
			}
		}
	if (dist[e] > money)dist[e] = INF;
	return dist[e];
	}
int main() {
	cin >> n >> m >> st >> ed >> money; f;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		long long value; cin >> a >> b >> value;
		v[a].push_back({ value,b });
		v[b].push_back({ value,a });
	}
	int answer = 0;
	int start = 0;
	int end = 1e9;
	int mid = 0;
	while(start<=end&&answer<50){
		 mid = (start + end) / 2;
		fill(dist, dist + n + 1, INF);
		dist[st] = 0;
		if (diac(st, ed, mid) != INF)end = mid;
		else start = mid+1;
		answer++;
	}
	answer = mid;
	if (answer >= 1e9)cout << "-1";
	else cout << answer;
}