#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 100001
using namespace std;
int dp[MAX];
vector<int>v;
int main() {
	int a, b; cin >> a >> b;
	for (int i = 0; i < a; i++) {
		int c; cin >> c;
		v.push_back(c);
	}
	for (int i = 0; i < b; i++) {
		dp[0] += v[i];
	}
	int start = 1;
	int end = b;
	int M = -1e9;
	for (int i = 1; i < a-b; i++) {
		dp[i] = dp[i - 1] - v[start] + v[end];
		M = max(M, dp[i]);
		start++;
		end++;
	}
	cout << M;
}