#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, m;
vector<int>v;
int ans = 2000000000;
int main() {
	cin >> n >> m; f;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (auto T : v) {
		int k=lower_bound(v.begin(), v.end(), T + m) - v.begin();
		if(k==n)continue;
		int low = v[k] - T;
		ans = min(low, ans);
		if (ans == m)break;
	}
	cout << ans;
}