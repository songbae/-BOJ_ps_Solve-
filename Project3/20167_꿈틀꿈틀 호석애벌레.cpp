#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int dp[20];
bool check[21];
int n, m;
vector<int>v;
int answer = 0;
void dfs(int index, int target) {
	if (index >target) {
		int sum = 0;
		int cnt = 0;
		for (int i = 0; i < 20; i++) {
			if (!check[i]) {
				sum = 0;
				continue;
			}
			sum += v[i];
			if (sum >= m) {
				cnt += sum - m;
				sum = 0;
			}

		}
		answer = max(answer, cnt);
		return;
	}
	dfs(index + 1, target);
	check[index] = true;
	dfs(index + 1, target);
	check[index] = false;
	
}
int main() {
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	dfs(0, n-1);
	cout << answer;
}