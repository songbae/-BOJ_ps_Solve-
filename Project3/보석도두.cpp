#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<pair<int, int>>T;
vector<int>bag;
int n, k;
multiset<int>st;
bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second)return a.first < b.second;
	return a.second > b.second;
}
int main() {
	cin >> n >> k; f;
	for (int i = 0; i < n; i++) {
		int m, v; cin >> m >> v;
		T.push_back({ m,v });
	}
	sort(T.begin(), T.end(), cmp);
	for (int i = 0; i < k; i++) {
		int a; cin >> a;
		st.insert(a);
	}
	sort(bag.begin(), bag.end());
	long long sum = 0;
	for (int i = 0; i < T.size(); i++) {
		int weight = T[i].first;
		int value = T[i].second;
		auto k=st.lower_bound(weight);
		if (k == st.end())continue;
		st.erase(k);
		sum += value;
	}
	cout << sum;
}