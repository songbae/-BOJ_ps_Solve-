#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1000001
using namespace std;
int n, m;
vector<pair<int, int>>v;
int dp[MAX];
int ans[MAX];
int main() {
	cin >> n;
	int end = 0;
	for (int i = 0; i < n; i++) {
		int start, len; cin >> start >> len;
		if (dp[start] != 0)dp[start] = min(dp[start], len);
		else dp[start] = len;
		end = max(end, start+len);
	}
	int answer = 0;
	for (int i = 1; i <=end; i++) {
		if (dp[i] != 0){
			ans[i + 1] = max(ans[i]+1, answer);
			ans[i + dp[i]] = max(ans[i + dp[i]], ans[i-1]+1);
			answer = max(answer, ans[i]);
		}
		
		}
	for (int i = 1; i <= end; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	for (int i = 1; i <= end; i++) {
		cout << dp[i] << " ";
	}
	cout << answer;
}