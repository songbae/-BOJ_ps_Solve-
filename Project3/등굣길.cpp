#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, m;
bool check[101][101];
int dp[101][101];
int main() {
	cin >> n >> m;
	int a; cin >> a;
	for (int i = 0; i < a; i++) {
		int x, y; cin >> x >> y;
		check[x][y] = true;
	}
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[0][0] = 0;
	dp[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1)continue;
			if (check[i][j])continue;
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%1000000007;
		}
	}

	cout << dp[n][m];
}