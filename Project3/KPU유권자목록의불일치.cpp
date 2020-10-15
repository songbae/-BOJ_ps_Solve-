#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int>a, b, c;
int n, m, k;
map<string, int>M;
vector<int>ans;
int main() {
	cin >> n >> m >> k; f;

	for (; n--;) {
		int t; cin >> t; a.push_back(t);
	}
	for (; m--;) {
		int t; cin >> t; b.push_back(t);
	}
	for (; k--;) {
		int t; cin >> t; c.push_back(t);
	}
	a.erase(unique(a.begin(), a.end()), a.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	c.erase(unique(c.begin(), c.end()), c.end());
	for (auto T : b)cout << T << " ";
	for (auto T : a)M.insert({ to_string(T),1 });
	for (auto T : b) {
		if (M[to_string(T)] == 1) {
			ans.push_back(T);
			M[to_string(T)]++;
		}
		else {
			if (M[to_string(T)] == 0)M.insert({ to_string(T),1 });
			else M[to_string(T)]++;
		}
	}
	for (auto T : c) {
		if (M[to_string(T)] == 1) {
			ans.push_back(T);
			M[to_string(T)]++;
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (auto T : ans)cout << T << "\n";
}