#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n;
vector<vector<int>>v;
int cnt[101];
bool check[101];
int ans;
void dfs(int st) {
	for (int i = 0; i < v[st].size(); i++) {
		if (check[v[st][i]])continue;
		check[v[st][i]] = true;
		dfs(v[st][i]);
	}
	cnt[st]++;
}
int main() {
	cin >> n;
	v.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 1; i <= n; i++){
		memset(check, false, sizeof(check));
	dfs(i);
	}
	int num = 0;
	int big = n;

	for (int i = 1; i <= n; i++) {
		if (cnt[i] == big) {
			num++;
			ans = i;
		}
	}
	if (num > 1 || ans == 0)cout << "-1";
	else cout << ans;
}