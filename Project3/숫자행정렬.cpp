#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<vector<int>>v;
vector<pair<string,int>>st;
int n;
bool cmp(pair<string, int>a, pair<string, int>b) {
	int x = a.first.size();
	int y = b.first.size();
	int num = abs(x-y);
	if(x!=y){
		if (x > y) {
			for (int i = 0; i < num; i++) {
				a.first += '0';
			}
		}
		else {
			for (int i = 0; i < num; i++) {
				b.first += '0';
			}
		}
	
	}
	return a.first < b.first;
}
int main() {
	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++) {
		while (1) {
			int a; cin >> a;
			if (a == -1)break;
			v[i].push_back(a);
		}
	}
	for (int i = 0; i < n; i++) {
		string s = "";
		for (int j = 0; j < v[i].size(); j++) {
			s += to_string(v[i][j]);
		}
		st.push_back({ s,i });
	}
	sort(st.begin(), st.end(), cmp);
	int cnt = 0;
	for (auto t : st) {
		cnt++;
		for (int i = 0; i < v[t.second].size(); i++) {
			cout << v[t.second][i];
			if (i != v[t.second].size() - 1)cout << " ";
		}
		if (cnt != n)cout << endl;
	}
}