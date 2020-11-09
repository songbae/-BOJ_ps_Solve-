#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n,m;
vector<int>T;
vector < vector<int>>connect;
int arr[1001];
long long tt[1001];
int target;
void dfs(int start, long long time) {
	arr[start]--;
	if (start == target) {
		tt[start] = max(tt[start], time);
		return;
	}
	for (int i = 0; i < connect[start].size(); i++) {
		int x = connect[start][i];
		long long s_time = T[x];
		arr[x]--;
		if (arr[x] > 0) {
			tt[x] = max(tt[x], time + s_time);
			continue;
		}
		else if(arr[x]==0)dfs(x, max(time+s_time,tt[x]));

	}
	return;
}
int main() {
	cin >> n; f;
	while (n--) {
		connect.clear();
		T.clear();
		memset(arr, false, sizeof(arr));
		memset(tt, false, sizeof(tt));
		int a, b; cin >> a >> b;
		T.resize(a+1);
		connect.resize(a+1);
		for (int i = 1; i <= a; i++) cin >> T[i];
		for (int i = 0; i < b; i++) {
			int c, d; cin >> c >> d;
			connect[c].push_back(d);
			arr[d]++;
		}
		cin >> target;
		for (int i = 1; i <= a; i++) {
			if (arr[i] == 0)dfs(i,T[i]);
		}
		cout << tt[target] <<"\n";
	}
}