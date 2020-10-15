#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 123457
using namespace std;
int n; char s;
vector<vector<long long>>v;
int node[MAX];
long long dp[MAX];
bool check[MAX];
queue<pair<int, long long>>q;
void dfs(int x){
	for (int i = 0; i<v[x].size(); i++) {
		int next = v[x][i];
		if (check[next])continue;
		check[next] = true;
		dfs(next);
		dp[x] += dp[next];
		}
	if (node[x]+dp[x] >= 0)dp[x] += node[x];
	else dp[x] = 0;
}
int main() {
	cin >> n; f;
	v.resize(n + 1);
	for (int i = 2; i <= n; i++) {
		int a, b; cin >> s >> a >> b;
		if (s == 'S') {
			v[i].push_back(b); v[b].push_back(i);
			node[i] = a;
		}
		else {
			v[i].push_back(b); v[b].push_back(i);
			node[i] = -a;
		}
	}
	check[1] = true;
	dfs(1);
	cout << dp[1];
}
