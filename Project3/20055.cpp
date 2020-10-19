#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
deque<pair<int, int>>dq;
int n, m, num,a;
int main() {
	cin >> n >> m; f;
	for (int i = 0; i < 2 * n; i++) {
	 cin >> a; dq.push_back({ a,0 });
	}
	while (m>0) {
		num++;
		pair<int, int>T = dq.back();
		dq.pop_back();
		dq.push_front(T);
		if (dq[n - 1].second == 1)dq[n - 1].second = 0;
		for (int i = n - 2; i >= 0; i--) {
			if (dq[i].second==1&&dq[i + 1].second == 0&&dq[i+1].first>0) {
				dq[i + 1].second = 1;
				dq[i + 1].first--;
				if (dq[i + 1].first == 0)m--;
				dq[i].second = 0;
			}
		}
		if (dq[n - 1].second == 1)dq[n - 1].second = 0;
		if (dq.front().first > 0) {
			dq.front().first--;
			dq.front().second = 1;
			if (dq.front().first == 0)m--;
	}
	}
	cout << num;
}