#include<bits/stdc++.h>
using namespace std;
int k, b, i; vector<string> v; vector<string>v1;
typedef string p;
bool cmp(p a, p b) {
	if (!v1.empty()) {
		return a + v1[0] + b + v1[0] < b + v1[0] + a + v1[0];
	}
	return a + b < b + a;
}
bool cmp1(p a, p b) {
	return a + b < b + a;
}
int main() {
	cin >> k;
	for (; i < k; i++) {
		p a; cin >> a;
		if (a[0] == '0')v1.push_back(a);
		else v.push_back(a);
	}
	if (v.empty()) {
		cout << "INVALID";
		return 0;
	}
	sort(v1.begin(), v1.end());
	sort(v.begin(), v.end(), cmp);
	for (auto t : v1)v.push_back(t);
	sort(v.begin() + 1, v.end(), cmp1);
	for (auto t : v)cout << t;
}