#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
#define INF 1e18
#define MAX 1000000
using namespace std;
pair<ll, ll>tree[MAX];
vector<ll>v;
int n, m;
pair<ll, ll> init(int node, int start, int end) {
	if (start == end) {
		tree[node].first = tree[node].second = v[start];
		return tree[node];
}
	else {
		int mid = (start + end) / 2;
		pair<ll, ll> left = init(2 * node, start, mid);
		pair<ll, ll> right = init(2 * node + 1, mid + 1, end);
		tree[node].first = min(left.first, right.first);
		tree[node].second = max(left.second, right.second);
		return tree[node];
	}
}
pair<ll, ll>find(int node, int start, int end, ll left, ll right) {
	if (end < left || right < start)return { INF,-INF };
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	pair<ll, ll>nodeleft = find(2 * node, start, mid, left, right);
	pair<ll, ll>noderight = find(2 * node + 1, mid + 1, end, left, right);
	ll small = min(nodeleft.first, noderight.first);
	ll big = max(nodeleft.second, noderight.second);
	pair<ll, ll>result = { small,big };
	return result;
}
int main() {
	cin >> n >> m; f;
	for (int i = 0; i < n; i++) {
		ll a; cin >> a; v.push_back(a);
	}
	init(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		ll b, c; cin >> b >> c;
		pair<ll, ll>ans = find(1, 0, n - 1, b - 1, c - 1);
		cout << ans.first << " " << ans.second << "\n";
	}
	
}