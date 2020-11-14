#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int check[26];
int ans ,cnt;
string prime, ed;
int dp[1001][1001];
int edit(string source, string target) {
	int n = source.size();
	for (int i = 0; i < 26; i++) {
		memset(check, false, sizeof(check));
		 cnt = 0;
		string tt = "";
		for (int j = 0; j < source.size(); j++) {
			char c = 0;
			if (source[j] + i > 122) c = source[j] + i - 26;
			else c = source[j]+i;
			tt += c;
		}
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= n; k++) {
				if (j == 0 || k == 0) {
					dp[j][k] = 0;
				}
				else if (tt[j - 1] == target[k - 1]) {
					dp[j][k] = 1 + dp[j - 1][k - 1];
				}
				else {
					dp[j][k] = max(dp[j - 1][k], dp[j][k - 1]);
				}
			}
		}
		cnt = (n - dp[n][n]) * 2;
		ans = min(cnt, ans);
	}
	return cnt;
}

int main() {
	string p ="";
	string k = "";
	cin >> p >> k;
	cout << edit(p, k);
}