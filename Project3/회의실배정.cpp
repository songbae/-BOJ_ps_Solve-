#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector < pair<int, int>>v;
bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second)return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int n,M; f; cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b, });
	}
	sort(v.begin(), v.end(), cmp);
	int end = -1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].first >= end) {
			ans++;
			end = v[i].second;
		}
	}
	cout << ans;
}