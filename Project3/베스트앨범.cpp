#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
map<string, int>genre;
vector < pair<int, pair<string, int>>>v;
vector<pair<string, int>>order;
bool cmp(pair<string, int>a, pair<string, int>b) {
	return a.second > b.second;
}
bool cmp1(pair<int, pair<string, int>>a, pair<int, pair<string, int>>b) {
	if (a.first == b.first)return a.second.second < b.second.second;
	return a.first > b.first;
}
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string a; int b; cin >> a >> b;
		if (genre.count(a))genre[a] += b;
		else genre.insert({ a,b });
		v.push_back({ b,{a,i} });
	}
	for (auto t : genre) {
		order.push_back({ t.first,t.second });
	}
	sort(order.begin(), order.end(),cmp);
	sort(v.begin(), v.end(), cmp1);
	for (auto t : order) {
		int cnt1 = 0;
		for (int i = 0; i < v.size(); i++) {
			if (t.first == v[i].second.first) {
				if (cnt1 == 2)break;
				cnt1++;
				cout << v[i].second.second << endl;

			}
		}
	}
}