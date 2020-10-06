#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1000001
using namespace std;
int n, ans;
vector<int>v[MAX];
vector<int>tree[MAX];//역방향 트리 
bool check[MAX];
int dp[MAX][2];//
void treedp(int x) {
	for (int i = 0; i < v[x].size(); i++) {
		int next = v[x][i];
		if (!check[next]) {
			check[next] = true;
			treedp(next);
			dp[x][1] += min(dp[next][1], dp[next][0]);
			dp[x][0] += dp[next][1];
		}
	}
	dp[x][1] += 1;
}
int main() {
	cin >> n; memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	check[1] = true;
	treedp(1);
	cout << min(dp[1][0],dp[1][1]);
 }