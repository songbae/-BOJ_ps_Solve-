#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mod 10007
using namespace std;
long long dp[1001][10];
int num[10] = { 10,9,8,7,6,5,4,3,2,1 };
int n;
int main() {
	cin >> n;
	fill(dp[1], dp[1] + 10, 1);
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				dp[i][k] += (dp[i - 1][j])%mod;
			}
			}
		}
	long long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += ((dp[n-1][i]%mod)*num[i])%mod;
	}
	if (n == 1)cout << "10";
	else cout << sum%mod;
}