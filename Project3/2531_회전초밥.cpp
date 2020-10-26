#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, d, k, c, ans, st, ed;
map<int, int>S;
set<int>P;
vector<int>v;
int arr[3001];
int main() {
	cin >> n >> d >> k >> c; f;
	for (int i = 0; i < n; i++) {
		int t; cin >> t; v.push_back(t);
	}
	for (int i = 0; i < n; i++) {
		v.push_back(v[i]);
	}
	st = 0;
	ed = k-1;
	int size = 0;
	for (int i = 0; i <= ed; i++) {
		if (arr[v[i]] == 0) {
			size++;
			arr[v[i]]++;
		}
		else arr[v[i]]++;
	}
	ans = size;
		while (1) {
			if (arr[c] == 0) {
				ans = max(ans, size + 1);
			}
			arr[v[st]]--;
			if (arr[v[st]] == 0)size--;
			st++;
			ed++;
			if (ed == v.size())break;
			arr[v[ed]]++;
			if (arr[v[ed]] == 1)size++;
			ans = max(size, ans);
		}
	cout << ans;
}