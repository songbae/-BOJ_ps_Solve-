#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n;
vector<vector<int>>node;
int depth[1001];
vector < vector<int>>v;
queue<int>q;
int ans;
void topology() {
	while (!q.empty()) {
		int x = q.front();
		int cnt = 0;
		sort(node[x].begin(), node[x].end(), greater<int>());
		if (node[x].size() == 1)cnt = node[x][0];
		else {
			if (node[x][0] == node[x][1])cnt = node[x][0] + 1;
			else cnt = node[x][0];
		}
		ans = max(cnt, ans);
		q.pop();
		for (int i = 0;i < v[x].size(); i++) {
			int nx = v[x][i];
			node[nx].push_back(cnt);
			if (--depth[nx] == 0)q.push(nx);
		}

	}
}
int main() {
	cin >> n;
	while (n--) {
		ans = 0;
		v.clear();
		node.clear();
		memset(depth, false, sizeof(depth));
		int num, test, edge; cin >> test >> num >> edge;
		v.resize(num + 1);
		node.resize(num + 1);
		for (int i = 0; i < edge; i++) {
			int a, b; cin >> a >> b;
			depth[b]++;
			v[a].push_back(b);
		}

		for (int i = 1; i <= num; i++) {
			if (depth[i] == 0) {
				q.push(i);
				node[i].push_back(1);
			}
	}
		topology();
		cout << test << " " << ans << endl;
}

}