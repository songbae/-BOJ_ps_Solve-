#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, m;
vector<int> v;
vector<int>tt;
vector<vector<int>>ans;
bool check[9];
map<string, int>st;
void dfs(int idx, int cnt, int target) {
	if (cnt == target) {
		string s = "";
		for (auto t : tt)s =s+" "+ to_string(t);
		if (!st.count(s)) {
			st.insert({ s,1 });
			ans.push_back(tt);
		}
		return;
	}
	for (int i = idx; i < v.size(); i++) {
		tt.push_back(v[i]);
		dfs(i, cnt + 1, target);
		tt.pop_back();
	}
	return;
}
int main() {
	cin >> n >> m; f;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	dfs(0, 0, m);
	for (int i = 0; i < ans.size(); i++) {
		for (auto t : ans[i])cout << t << " ";
		cout << "\n";
	}
}