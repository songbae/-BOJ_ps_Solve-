#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, m;
vector<int>v;
queue<int>q;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		q.push(a);
	}
	m%=n;
	for (int i = 0; i < m; i++) {
		int x = q.front();
		q.pop();
		q.push(x);
	}
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
}