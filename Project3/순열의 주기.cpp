#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n;
int check[1002];
vector<int>v;
vector<int>ans;
int main() {
	cin >> n; 
	v.push_back(0);
	for (int i = 1; i <= n; i++) {
		int a; cin >> a; v.push_back(a);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (check[i])continue;
		cnt++;
		check[i] = true;
		int k = v[i];
		while (1) {
			if (k==i)break;
			check[k] = true;
			k = v[k];
		}
	}
		memset(check, false, sizeof(check));
		cout << cnt << endl;
	for (int i = 1; i <= n; i++) {
		if (check[i])continue;
		cnt--;
		check[i] = true;
		ans.push_back(i);
		int k = v[i];
		while (1) {
			ans.push_back(k);
			if (k==i)break;
			check[k] = true;
			k = v[k];

		}
		for (int j = 0; j < ans.size(); j++) {
			cout << ans[j];
			if (j != ans.size() - 1)cout << " ";
		}
		if (cnt != 0)cout << endl;
		ans.clear();
	}
}