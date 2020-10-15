#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n;
vector<pair<int, int>>v;
int main() {
	cin >> n;
	int suma = 0;
	int sumb = 0;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		suma += a;
		sumb += b;
		int lead = abs(suma - sumb);
		if (suma > sumb)v.push_back({ lead,1 });
		else v.push_back({ lead,2 });
	}
	sort(v.begin(), v.end(), greater<pair<int,int>>());
	cout << v[0].second << " " << v[0].first;
}