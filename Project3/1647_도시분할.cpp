#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, m,cnt,ans;
vector <pair<int,pair<int,int>>>v;
int parent[100001];
int find(int x) {
	if (parent[x] == x)return x;
	return parent[x] = find(parent[x]);
}
bool Union(int x, int y) {
	int a = find(x);
	int b = find(y);
	 if (a > b)swap(a, b);// a가 항상작다
	 if (a == b)return false;
	else parent[b] = a;
	return true;
}
int main() {
	cin >> n >> m; f;
	v.resize(n); 
	for (int i = 0; i < m; i++) {
		int a, b,c; cin >> a >> b>>c;
		v.push_back({ c,{a,b} });
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++)parent[i] = i;
	for (int i = 0; i < v.size(); i++) {
		if (cnt >= n-2)break;
		int cost = v[i].first;
		int st = v[i].second.first;
		int ed = v[i].second.second;
		if (!Union(st, ed))continue;
		ans += cost;
		cnt++;
	}
	cout << ans;
}