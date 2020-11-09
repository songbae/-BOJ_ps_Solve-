#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, m,cur,a,node;
int depth[1001];
vector<vector<int>>v;
vector<int>ans;
void topology(int st) {
	depth[st]--;
	ans.push_back(st);
	for (auto T:v[st]) if (--depth[T] == 0)topology(T);
}
int main() {
	cin >> n >> m;
	v.resize(n+1);
	for (int i = 0; i < m; i++) {cin >> a;
		for (int j = 0; j < a; j++) {
			 cin >> node;
			if (j == 0) {
				cur = node;
				continue;
			}
			v[cur].push_back(node);
			depth[node]++;
			cur = node;
		}
	}
	for (int i = 1; i <= n; i++)if (depth[i] == 0)topology(i);
	if (ans.size() != n)cout << "0";
	else for (auto T : ans)cout << T << " ";

}