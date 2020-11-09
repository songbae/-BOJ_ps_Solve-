#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n,cnt;
int arr[10001];
int depth[10001];
int max_time[10001];
vector<vector<int>>v;

void dfs(int x, int time) {
	depth[x]--;
	max_time[x] = max(max_time[x], time);
	for (int i = 0; i < v[x].size(); i++) {
		int nx = v[x][i];
		int s_time = arr[nx];
		depth[nx]--;
		if (depth[nx] > 0) {
			max_time[nx] = max(max_time[nx], time + s_time);
			continue;
		}
		else if (depth[nx] == 0)dfs(nx, max(time + s_time, max_time[nx]));
	}
  }
int main() {
	cin >> n;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		int num; cin >> num;
		for (int j= 0; j < num; j++) {
			int k; cin >> k;
			depth[i]++;
			v[k].push_back(i);
		}

	}
	for (int i = 1; i <= n; i++) {
	if(depth[i]==0)	dfs(i,arr[i]);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, max_time[i]);
	}
	cout << ans;
}