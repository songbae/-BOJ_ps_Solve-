#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, m;
vector<int> v;
vector<int>tt;
vector<vector<int>>ans;
bool check[9];
map<string, int>st;
void dfs( int cnt, int target) {
	if (cnt == target) {
		string s = "";
		for (auto t : tt)s += to_string(t);
		if (!st.count(s)) {
			st.insert({ s,1 });
			ans.push_back(tt);
		}
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (check[i])continue;
		check[i] = true;
		tt.push_back(v[i]);
		dfs( cnt + 1, target);
		tt.pop_back();
		check[i] = false;
	}
	return;
}
int main() {
	cin >> n >> m; 
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	dfs(0,m);
	for (int i = 0; i < ans.size(); i++) {
		for (auto t : ans[i])cout << t << " ";
		cout << "\n";
	}
}