#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
string s, s1;
int dp[1001][1001];
int main() {
	cin >> s >> s1;
	s = "0" + s;
	s1 = "0" + s1;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < s1.size(); j++) {
			if (i == 0 || j == 0)continue;
			if (s[i] == s1[j])dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	int n = s.size()-1;
	int m = s1.size()-1;
	int cnt = dp[n ][m];
	cout << cnt << endl;
	string s2 = "";
	while (dp[n][m]!= 0) {
		if (dp[n][m] == dp[n][m - 1]) m--;
		else if (dp[n][m] == dp[n - 1][m ])n--;
		else if (dp[n][m] == dp[n - 1][m-1]+1) {
			s2 += s[n];
			n--;
			m--;
		}
	}
	reverse(s2.begin(), s2.end());
	cout << s2;
}