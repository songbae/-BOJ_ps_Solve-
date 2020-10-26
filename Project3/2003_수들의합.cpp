#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
map<int, int>M;
vector<int>v;
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; v.push_back(a);
	}
	int st = 0;
	int ed = 0;
	int cnt = 0;
	int cur = v[st];
	while (1) {
		if (cur == m) {
			cnt++;
			ed++;
			if (ed == n)break;
			cur += v[ed];
		}
		else if (cur < m) {
			ed++;
			if (ed == n)break;
			cur += v[ed];
		}
		else if (cur > m) {
			if (st == ed) {
				ed++;
				if (ed == n)break;
				cur += v[ed];
			}
			else {
				cur -= v[st];
				st++;
			}
		}
	}
	cout << cnt;
}