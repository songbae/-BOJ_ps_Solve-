#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1000001
using namespace std;

int dp[MAX];

int main() {
	int n; cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 1000000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2])%15746;
	}
	cout << dp[n];
}