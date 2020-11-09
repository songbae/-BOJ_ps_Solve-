#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1000000009
using namespace std;
int n, m;
bool check[41];
int dp[41];
vector<int>v;
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a;	cin >> a; check[a] = true;
	}
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)dp[i] = dp[i - 1] + dp[i - 2];
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (check[i]) {
			v.push_back(cnt);
			cnt = 0;
			continue;
		}
		cnt++;
	}
	v.push_back(cnt);
	int sum = 1;
	for (auto T : v) {
		if (T == 0)continue;
		sum *= dp[T];
	}
	cout << sum;

}