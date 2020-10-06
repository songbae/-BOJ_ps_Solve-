#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
#define MAX 3000001
using namespace std;
vector<ll>v;
ll tree[MAX];
ll n, m, k;

ll init(ll start, ll end, ll node) {
	if (start == end)return tree[node] = v[start];
	ll mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);

}
ll sum(ll start, ll end, ll node, ll left, ll right) {
	//범위밖 탐색종료
	if (left > end || right < start)return 0;
	//범위안에있는경우 탐색종료
	if (left <= start && end <= right)return tree[node];
	ll mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);

}
void update(ll start, ll end, ll node, ll index, ll diff) {
	//범위 밖일경우 종료
	if (index<start || index>end)return;
	tree[node] += diff;
	if (start == end)return;
	ll mid = (start + end) / 2;
	update(start, mid, node * 2, index, diff);
	update(mid + 1, end, node * 2 + 1, index, diff);
}
int main() {
	cin >> n >> m >> k; f;
	for (int i = 0; i < n; i++) { ll t; cin >> t; v.push_back(t); }
	init(0, n - 1, 1);
	for (int i = 0; i < m + k; i++) {
		ll a, b, c; cin >> a >> b >> c;
		if (a == 1) {
			update(0, n - 1, 1, b - 1, c - v[b - 1]);//b->c로 업데이트한다 ;
			v[b - 1] = c;
		}
		else cout << sum(0,n-1 ,1,b-1,c-1 ) << "\n";// b-c의 값을 구한다.
	}
}