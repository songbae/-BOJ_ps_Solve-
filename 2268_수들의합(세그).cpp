#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, m;
vector<long long>tree;
long long arr[1000001];
//int maketree(int st, int ed, int num) {
//	if (st == ed)return tree[num] = arr[st];
//	int mid = (st + ed) / 2;
//	return tree[num] = maketree(st, mid, num * 2) + maketree(mid + 1, ed, num * 2 + 1);
//}
void update(int st,int ed,int node,int index,long long diff) {
	if (index<st || index>ed)return;
	tree[node] += diff;
	if (st == ed)return;
	int mid = (st + ed) / 2;
	update(st, mid, node * 2, index, diff);
	update(mid + 1, ed, node * 2 + 1, index, diff);
}
long long search(int st,int ed,int node,int left, int right) {
	if (left > ed || right < st) return 0;
	if (left <= st && ed <= right)return tree[node];
	int mid = (st + ed) / 2;
	return search(st, mid, node * 2, left, right) + search(mid + 1, ed, node * 2 + 1, left, right);
}
int main() {
	cin >> n >> m; f;
	tree.resize(4*n + 1);
	/*maketree(1,n,1);*/
	for (int i = 0; i < m; i++) {
		long long a, b, c; cin >> a >> b >> c;
		if (a == 0) {
			if (b > c)swap(b, c);
			cout << search(1, n, 1, b, c) << "\n";
		}
		if (a == 1) {
			update(1, n, 1, b, c - arr[b]);
			arr[b] = c;
		}

	}
}