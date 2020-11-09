#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, m;
vector<int>v;
int dp[1001];
int main() {
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		int x = v[i];
		for (int j = i + 1; j < n; j++) {
			if (v[j] > x)dp[j]=max(dp[j],dp[i]+1);
		}
	}
	int MAX = 0;
	for (int i = 0; i < n; i++)MAX = max(MAX, dp[i]);
	cout << MAX+1;
}