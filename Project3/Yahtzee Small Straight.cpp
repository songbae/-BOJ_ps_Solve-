#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector<int>v;
bool ok;
int main() {
	for (int i = 0; i < 5; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	if (v.size() >= 4) {
		for (int i = 0; i < v.size() - 3; i++)
			if (v[i] == v[i + 1] - 1 && v[i] == v[i + 2] - 2 && v[i] == v[i + 3] - 3)ok = true;
	}
	if (ok)cout << "YES";
	else cout << "NO";
}