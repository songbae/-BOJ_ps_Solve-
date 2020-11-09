#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mod 1000000000
using namespace std;
int dp[100],n,cnt=1,sum;
int main() {
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < 100; i++)dp[i] = (dp[i - 1]%mod * dp[i - 1]%mod)%mod;
	while (n > 0) {
		int res = n % 2;
		n /= 2;
		if (res == 1)sum += dp[cnt];
		sum %= mod;
		cnt++;
	}
	cout << sum;
}