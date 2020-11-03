#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1000000009
using namespace std;
stack < pair<int, int>>st;
vector<int>v;
int n;
int main() {
	cin >> n; f;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		if (st.empty()) {
			v.push_back(0);
			st.push({ a,i });
		}
		else {
			while (!st.empty()&&st.top().first < a) {
				st.pop();
			}
			if (st.empty()) {
				v.push_back(0);
				st.push({ a,i });
			}
			else {
				v.push_back(st.top().second);
				st.push({ a,i });
			}
		}
	}
	for (auto T : v)cout << T << " ";
}