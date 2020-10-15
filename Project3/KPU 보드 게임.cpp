#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, m;
vector<int>v;
vector<int>dice;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		if (c == '+')v.push_back(1);
		else v.push_back(-1);
	}
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		dice.push_back(a);
	}
	int cnt = 1;
	int start = 1;
	for (int i = 0; i < m; i++) {
		if (v[start - 1] > 0) {
			if (dice[i] + start < n)start += dice[i];
		}
		else {
			if (start - dice[i] >= 1)start -= dice[i];
		}
		if (start == 1)cnt++;
	}
	cout << cnt;
}