#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, m,a,b;
int depth[32001];
bool check[32001];
vector<vector<int>>v;
vector<int>ans;
priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
void topology(int st) {
	check[st] = true;
	ans.push_back(st);
	for (auto T : v[st])q.push({ --depth[T], T });
}
int main() {
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++){
		cin >> a >> b;
		depth[b]++;
		v[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		q.push({ depth[i],i });
	}
	while (!q.empty()||ans.size()<n) {
		int x = q.top().first;
		int y = q.top().second;
		q.pop();
		if (check[y])continue;
		topology(y);
	}
	 for (auto T : ans)cout << T << " ";

}