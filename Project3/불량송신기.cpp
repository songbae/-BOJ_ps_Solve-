#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
string a, b, c;
int n, m, k;
int max1, max2;
int main() {
	cin >> n >> m >> k;
	cin >> a >> b >> c;
	c.erase(unique(c.begin(), c.end()), c.end());
	for (int i = 0; i < c.size() - n; i++) {
		if (c[i] != a[0])continue;
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (c[i + j] == a[j])cnt++;
			else break;
		}
		max1 = max(max1, cnt);
	}
	for (int i = 0; i < c.size() - m; i++) {
		if (c[i] != b[0])continue;
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			if (c[i + j] == b[j])cnt++;
			else break;
		}
		max2 = max(max2, cnt);
	}
	if (k > n && max1 == n)cout << "YES" << endl;
	else cout << "NO" << endl;
	if (k > m && max2 == m)cout << "YES";
	else cout << "NO";
}