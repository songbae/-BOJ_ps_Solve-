#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1e9
using namespace std;
vector < vector<pair<int, int>>>v;
int n, m, k;
vector<int>ans;
bool check[10001];
vector < vector<int>>p;
int answer = 1e9;
void dfs(int st, int target,int cnt) {
	if (cnt >n)return;
	if (st == target) {
		vector<int>temp = ans;
		sort(temp.begin(), temp.end());
		int sum = 0;;
		for (int i = 0; i < temp.size() - k; i++)sum += temp[i];
		answer = min(sum, answer);
		return;
	}
	for (int i = 0; i < v[st].size(); i++) {
		int next = v[st][i].first;
		int cost = v[st][i].second;
		if (check[next])continue;
		check[next] = true;
		ans.push_back(cost);
		dfs(next, target,cnt+1);
		check[next] = false;
		ans.pop_back();
		}
		
	return;
}
int main() {
	cin >> n >> m >> k;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, val; cin >> a >> b >> val;
		v[a].push_back({ b,val });
		v[b].push_back({ a,val });
	}
	check[1] = true;
	dfs(1, n,1);
	cout << answer;
}