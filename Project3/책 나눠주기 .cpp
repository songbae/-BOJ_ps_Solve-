#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n;
bool check[1001];
vector<pair<int, int>>v;
bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second)return a.first < b.first;
	return a.second < b.second;
}
int main() {
	f; cin >> n;
	while (n--) {
		int a, b; cin >> a >> b;
		for (int i = 0; i < b; i++) {
			int c, d; cin >> c >> d;
			v.push_back({ c,d });
		}
		sort(v.begin(), v.end(), cmp);
		int cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			int start = v[i].first;
			int end = v[i].second;
			for (int j = start; j <= end; j++) {
				if (check[j])continue;
				check[j] = true;
				cnt++;
				break;
			}
		}
		cout << cnt << "\n";
		v.clear();
		memset(check, false, sizeof(check));
	}
}