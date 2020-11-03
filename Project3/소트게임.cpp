#include<bits/stdc++.h>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1000000009
using namespace std;
vector<int>v;
bool check;
int n, k;
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; v.push_back(a);
	}
	int cnt = 0;
		while (1) {
			bool ok = false;
		for (int i = 0; i < v.size(); i++){
			if (v[i] > i + 1&&i+k-1<v.size()) {
				ok = true;
				cnt++;
				reverse(v.begin() + i, v.begin() + i + k);
			}
			if (v[i]<i + 1 && i - k + 1>=0) {
				ok = true;
				cnt++;
				reverse(v.begin() - k + i + 1, v.begin() + i);
			}
			}
		if (!ok)break;
		if (cnt > 100) {
			check = true;
			break;
		}
	}
		if (check)cout << "-1";
		else cout << cnt;
}