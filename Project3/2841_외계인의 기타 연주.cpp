#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<pair<int,int>>v;
int n, m,cnt;
stack<int>st[8];
int main() {
	cin >> n >> m; f;
	for (int i = 0; i < n; i++) {
		 int a, b; cin >> a >> b;
		 if (st[a].empty()) {
			 st[a].push(b);
			 cnt++;
		 }
		 else {
			 if (st[a].top() == b)continue;
			 if (st[a].top() < b) {
				 st[a].push(b);
				 cnt++;
			 }
			 else if (st[a].top() > b) {
				 while (!st[a].empty()&&st[a].top() > b) {
					 st[a].pop();
					 cnt++;
				 }
				 if (!st[a].empty()&&st[a].top() == b)continue;
				 st[a].push(b); cnt++;
			 }
		 }
	}
	cout << cnt;
}