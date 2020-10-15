#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, m;
int Candidate[10001];
vector<pair<int, int>>v;
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		Candidate[a]++;
	}
	for (int i = 0; i < 10001; i++) {
		v.push_back({ Candidate[i],i });
	}
	sort(v.begin(), v.end(), greater<pair<int, int>>());
	cout << v[2].second;
}