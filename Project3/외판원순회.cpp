#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1e9
using namespace std;
int n, arr[16][16], dp[16][1<<16];

int dfs(int node, int visit) {
	if (dp[node][visit] != 0) return dp[node][visit];
	if (visit == (1 << n) - 1) {
		if (arr[node][0] > 0) return arr[node][0];
		else return MAX;
	}
	int result = MAX;
		for (int i = 0; i < n; i++) {
			if (!(visit & (1 << i)) && arr[node][i] != 0) {
				result = min(result, arr[node][i] + dfs(i, visit + (1 << i)));
			}		
		}
		dp[node][visit] = result;
		return result;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)cin >> arr[i][j];
	cout<<dfs(0, 1);

}